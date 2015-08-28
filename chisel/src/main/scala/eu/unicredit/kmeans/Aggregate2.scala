package eu.unicredit.kmeans

import Chisel._
import scala.math.sqrt
import scala.util.Random

case class SelectivePointOps(n: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    //base
    val p1x = Dbl(INPUT)
    val p1y = Dbl(INPUT)

    //operation type
    val operation = UInt(INPUT, width = 4)

    //second operand
    val p2x = Dbl(INPUT)
    val p2y = Dbl(INPUT)

    val den = Dbl(INPUT)

    //output
    val poutx = Dbl(OUTPUT)
    val pouty = Dbl(OUTPUT)

    val out = Dbl(OUTPUT)

    //limits
    val cent = UInt(INPUT, width = 32)
  }

  val po = Module(PointOps())

  po.io.p1x <> io.p1x
  po.io.p1y <> io.p1y
  po.io.p2x <> io.p2x
  po.io.p2y <> io.p2y
  po.io.den <> io.den
  io.out <> po.io.out
  po.io.operation <> io.operation

  io.poutx := po.io.poutx
  io.pouty := po.io.pouty
  when (io.cent != UInt(n) && io.operation === UInt(1)) {
    io.poutx := io.p1x
    io.pouty := io.p1y
  }
}

case class SelectiveAverageOp(n: Int, nCent: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val xs = Vec.fill(n)(Dbl(INPUT))
    val ys = Vec.fill(n)(Dbl(INPUT))

    val cent = Vec.fill(n)(UInt(INPUT, width = 32))

    val outX = Dbl(OUTPUT)
    val outY = Dbl(OUTPUT)
  }

  val po =
    for (i <- 0 to n) yield {
      Module(SelectivePointOps(nCent))
    }

  val count =
      Vec(for (c <- 0 until n) yield {
        io.cent(c)
      }).count{ x: UInt => x === UInt(nCent)}

  po(0).io.p1x := Dbl(0.0)
  po(0).io.p1y := Dbl(0.0)

  po(0).io.p2x := io.xs(0)
  po(0).io.p2y := io.ys(0)

  po(0).io.cent := io.cent(0)

  po(0).io.operation := 1

  for (i <- 1 until n) yield {
    po(i).io.p2x <> io.xs(i)
    po(i).io.p2y <> io.ys(i)

    po(i).io.p1x <> po(i-1).io.poutx
    po(i).io.p1y <> po(i-1).io.pouty

    po(i).io.operation := 1

    po(i).io.cent := io.cent(i)
  }

  po(n).io.p1x <> po(n-1).io.poutx
  po(n).io.p1y <> po(n-1).io.pouty

  val conv = Module(IntToDblConversionOp(n))
  conv.io.in := count
  po(n).io.den <> conv.io.out

  po(n).io.operation := 3

  io.outX := po(n).io.poutx
  io.outY := po(n).io.pouty
  when (count <= UInt(0)) {
    io.outX := Dbl(0.0)
    io.outY := Dbl(0.0)
  }
}

case class CalcNewCentroids2Op(nPoints: Int, nCentroids: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val xs = Vec.fill(nPoints)(Dbl(INPUT))
    val ys = Vec.fill(nPoints)(Dbl(INPUT))
    val cent = Vec.fill(nPoints)(UInt(INPUT, width = 32))

    val centroidXs = Vec.fill(nCentroids)(Dbl(OUTPUT))
    val centroidYs = Vec.fill(nCentroids)(Dbl(OUTPUT))
  }

  val avgs =
    for (i <- 0 until nCentroids) yield {
      Module(SelectiveAverageOp(nPoints, i))
    }

  for (ip <- 0 until nPoints) {
    for (ic <- 0 until nCentroids) {
      avgs(ic).io.xs(ip) <> io.xs(ip)
      avgs(ic).io.ys(ip) <> io.ys(ip)

      avgs(ic).io.cent(ip) <> io.cent(ip)
    }
  }

  for (k <- 0 until nCentroids) {
    io.centroidXs(k) := avgs(k).io.outX
    io.centroidYs(k) := avgs(k).io.outY
  }
}

case class Algo(nPoints: Int, nCentroids: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val xs = Vec.fill(nPoints)(Dbl(INPUT))
    val ys = Vec.fill(nPoints)(Dbl(INPUT))

    val en = Bool(INPUT)
    val iterations = UInt(INPUT, width = 32)

    val done = Bool(OUTPUT)

    val centroidsXs = Vec.fill(nCentroids)(Dbl(OUTPUT))
    val centroidsYs = Vec.fill(nCentroids)(Dbl(OUTPUT))

    val debug = UInt(OUTPUT, width = 32)
  }

  val count = Reg(UInt(width = 32))

  when (io.en) {
    count := UInt(0)
  } .elsewhen(!io.en) {
    count := count + UInt(1)
  }

  val tempCentroidsXs =
    Vec.fill(nCentroids)(Reg(Dbl()))
  val tempCentroidsYs =
    Vec.fill(nCentroids)(Reg(Dbl()))

  val temp2CentroidsXs =
    Vec.fill(nCentroids)(Reg(Dbl()))
  val temp2CentroidsYs =
    Vec.fill(nCentroids)(Reg(Dbl()))


  val centroids =
    Module(CalcCentroidsOp(nPoints, nCentroids))

  val cluster =
    Module(CalcNewCentroids2Op(nPoints, nCentroids))

  when (count === UInt(0)) {
    for (i <- 0 until nCentroids) {
        tempCentroidsXs(i) := io.xs(i)
        tempCentroidsYs(i) := io.ys(i)
    }
  } .otherwise {
    for (i <- 0 until nCentroids) {
        tempCentroidsXs(i) := temp2CentroidsXs(i)
        tempCentroidsYs(i) := temp2CentroidsYs(i)
    }
  }

  for (i <- 0 until nCentroids) {
    centroids.io.centroidsXs(i) := tempCentroidsXs(i)
    centroids.io.centroidsYs(i) := tempCentroidsYs(i)
  }
  for (i <- 0 until nPoints) {
    centroids.io.xs(i) <> io.xs(i)
    centroids.io.ys(i) <> io.ys(i)
    cluster.io.xs(i) <> io.xs(i)
    cluster.io.ys(i) <> io.ys(i)

    cluster.io.cent(i) <> centroids.io.out(i)
  }

  for (i <- 0 until nCentroids) {
    temp2CentroidsXs(i) := Dbl(0.0)
    temp2CentroidsYs(i) := Dbl(0.0)
  }

  io.done := Bool(false)
  when (count < io.iterations) {

    for (i <- 0 until nCentroids) {
      temp2CentroidsXs(i) := cluster.io.centroidXs(i)
      temp2CentroidsYs(i) := cluster.io.centroidYs(i)
    }

  } .elsewhen (!io.en && count >= io.iterations) {
    io.done := Bool(true)
    count := io.iterations
  }

  for (i <- 0 until nCentroids) {
    io.centroidsXs(i) := temp2CentroidsXs(i)
    io.centroidsYs(i) := temp2CentroidsYs(i)
  }

  io.debug := count
}

case class AlgoTests(a: Algo) extends Tester(a) {

  def toDouble(x: BigInt): Double = java.lang.Double.longBitsToDouble(x.longValue)

  val iterations = 2

  val points =
    for (i <- 0 until a.nPoints) yield
      (Random.nextDouble, Random.nextDouble)

  //setup iterations to finish
  poke(a.io.en, true)
  poke(a.io.iterations, iterations)
  step(1)
  //check that is ok and set input
  poke(a.io.en, true)
  expect(a.io.done, 0)

  for (i <- 0 until a.nPoints) {
    poke(a.io.xs(i), points(i)._1)
    poke(a.io.ys(i), points(i)._2)
  }

  step(1)
  //start!
  poke(a.io.en, false)
  expect(a.io.debug, 0)
  expect(a.io.done, 0)

  //at this step centroids are the first N points
  /*
  expect(a.io.centroidsXs(0), 0.0)
  expect(a.io.centroidsYs(0), 0.0)
  expect(a.io.centroidsXs(1), 5.0)
  expect(a.io.centroidsYs(1), 5.0)
  */
  step(1)

  for (s <- 1 to iterations) {
    expect(a.io.debug, s)

    val last =
      if (s == iterations) 1
      else 0

    expect(a.io.done, last)

    val kstep = ScalaAlgo.run(points.toList, s, a.nCentroids)

    var check1 = scala.collection.mutable.ListBuffer[(Double, Double)]()

    for (i <- 0 until a.nCentroids)
      check1 = check1 :+ (toDouble(peek(a.io.centroidsXs(i))), toDouble(peek(a.io.centroidsYs(i))))
    println("from board -> "+check1)

    for (i <- 0 until a.nCentroids)
      check1 -= kstep(i)
    println("from board -> "+kstep)

    expect(check1.length == 0, "is empty?"+check1)

    step(1)
  }

  //End
  expect(a.io.debug, 2)
  expect(a.io.done, 1)

  expect(a.io.centroidsXs(0), 0.0)
  expect(a.io.centroidsYs(0), 0.0)
  expect(a.io.centroidsXs(1), 0.0)
  expect(a.io.centroidsYs(1), 0.0)

}

object ScalaAlgo {
  type Point = (Double, Double)

  implicit class RichPoint(val x: Point) extends AnyVal {
    def /(k: Double): Point = (x._1 / k, x._2 / k)

    def +(y: Point) = ((x._1 + y._1), (x._2 + y._2))
    def -(y: Point) = ((x._1 - y._1), (x._2 - y._2))

    def modulus = sqrt(sq(x._1) + sq(x._2))
  }

  def run(xs: List[Point], iters: Int, nCent: Int) = {
    var centroids = xs take nCent

    for (i <- 1 to iters) {
      centroids = clusters(xs, centroids) map average
    }
    //clusters(xs, centroids)
    centroids
  }

  def clusters(xs: List[Point], centroids: List[Point]) =
    (xs groupBy { x => closest(x, centroids) }).values.toList

  def closest(x: Point, choices: List[Point]) =
    choices minBy { y => dist(x, y) }

  def sq(x: Double) = x * x

  def dist(x: Point, y: Point) = (x - y).modulus

  def average(xs: List[Point]) = xs.reduce(_ + _) / xs.size
}
