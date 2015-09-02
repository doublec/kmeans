package eu.unicredit.kmeans

import Chisel._
import scala.util.Random
import scala.math.sqrt

case class DistanceOpTests(d: DistanceOp) extends Tester(d) {

  poke(d.io.p1x, 1.0)
  poke(d.io.p1y, 1.0)

  poke(d.io.p2x, 1.0)
  poke(d.io.p2y, 2.0)

  expect(d.io.out, 1.0)

  step(1)

  for { _ <- 1 to 10} {
    val x1 = Random.nextDouble
    val y1 = Random.nextDouble
    val x2 = Random.nextDouble
    val y2 = Random.nextDouble

    poke(d.io.p1x, x1)
    poke(d.io.p1y, y1)

    poke(d.io.p2x, x2)
    poke(d.io.p2y, y2)

    def sq(x: Double) = x * x
    expect(d.io.out, sqrt(sq(x1 - x2) + sq(y1 - y2)))
  }
}

case class Min2OpTests(m: Min2Op) extends Tester(m) {

  poke (m.io.value, 1.0)
  poke (m.io.oldValue, 2.0)

  poke (m.io.oldMin, 3)

  expect (m.io.newMin, m.i)
  expect (m.io.newValue, 1.0)

  step(1)

  poke (m.io.value, 3.0)
  poke (m.io.oldValue, 2.0)

  poke (m.io.oldMin, 4)

  expect (m.io.newValue, 2.0)
  expect (m.io.newMin, 4)

  step(1)


  for (_ <- 1 to 10) {

    val x = Random.nextDouble
    val y = Random.nextDouble

    val oldMin = {
      var _m = Random.nextInt
      while (_m == m.i) _m = Random.nextInt
      _m
    }

    poke (m.io.value, x)
    poke (m.io.oldValue, y)

    poke (m.io.oldMin, oldMin)

    var nm = oldMin
    var nv = y

    if (x < y) {
      nm = m.i
      nv = x
    }

    expect (m.io.newMin, nm)
    expect (m.io.newValue, nv)
    step(1)
  }

}

case class MinOpTests(m: MinOp) extends Tester(m) {

  for (_ <- 1 to 10) {
    val values = for (_ <- 0 until m.n) yield Random.nextDouble

    val min = {
      var minValue = Double.MaxValue
      var minIndex = -1
      for (i <- 0 until m.n) {
        if (minValue > values(i)) {
          minValue = values(i)
          minIndex = i
        }
      }
      minIndex
    }

    for (i <- 0 until m.n) {
      poke(m.io.values(i), values(i))
    }

    expect(m.io.out, min)

    step(1)
  }
}

case class ClosestOpTests(c: ClosestOp) extends Tester(c) {

  for (_ <- 1 to 10) {
    val pointX = Random.nextDouble
    val pointY = Random.nextDouble

    poke(c.io.pointX, pointX)
    poke(c.io.pointY, pointY)

    var min = Double.MaxValue
    var minIndex = -1
    for { i <- 0 until c.n} {
      val x = Random.nextDouble
      val y = Random.nextDouble

      poke(c.io.xs(i), x)
      poke(c.io.ys(i), y)

      def sq(x: Double) = x * x
      val dist = sqrt(sq(pointX - x) + sq(pointY - y))

      if (dist <= min) {
        min = dist
        minIndex = i
      }
    }

    expect(c.io.closest, minIndex)
    step(1)
  }
}

case class CalcCentroidsOpTests(c: CalcCentroidsOp) extends Tester(c) {

  for (_ <- 1 to 10) {
    val centroids =
      for (_ <- 0 until c.nCentroids) yield
        (Random.nextDouble, Random.nextDouble)

    val points =
      for (_ <- 0 until c.nPoints) yield
        (Random.nextDouble, Random.nextDouble)

    for (i <- 0 until c.nPoints) {
      poke(c.io.xs(i), points(i)._1)
      poke(c.io.ys(i), points(i)._2)
    }

    for (i <- 0 until c.nCentroids) {
      poke(c.io.centroidsXs(i), centroids(i)._1)
      poke(c.io.centroidsYs(i), centroids(i)._2)
    }
    val ci =
      for (i <- 0 until c.nCentroids) yield
        (i, centroids(i))

    def closest(p: (Double, Double)): Int = {

      def sq(x: Double) = x*x
      def dist(x: (Double, Double), y: (Double,Double)) =
        sqrt(sq(x._1 - y._1) + sq(x._2 - y._2))

      (ci minBy {x: (Int, (Double, Double)) => dist(x._2, p)})._1
    }

    for (i <- 0 until c.nPoints) {
      expect(c.io.out(i), closest(points(i)))
    }
    step(1)
  }
}

case class SelectiveAverageOpTests(s: SelectiveAverageOp) extends Tester(s) {

    poke(s.io.xs(0), 1.0)
    poke(s.io.xs(1), 2.0)
    poke(s.io.xs(2), 3.0)

    poke(s.io.ys(0), 1.0)
    poke(s.io.ys(1), 2.0)
    poke(s.io.ys(2), 3.0)

    poke(s.io.cent(0), 0)
    poke(s.io.cent(1), 1)
    poke(s.io.cent(2), 0)

    expect(s.io.outX, 2.0)
    expect(s.io.outY, 2.0)

    step(1)
}

case class CalcNewCentroidsOpTests(c: CalcNewCentroidsOp) extends Tester(c) {

  for (_ <- 1 to 10) {
    val x =
      for (_ <- 1 to c.nPoints) yield Random.nextDouble

    val y =
      for (_ <- 1 to c.nPoints) yield Random.nextDouble

    val cen =
      for (_ <- 1 to c.nPoints) yield Random.nextInt(c.nCentroids)

    for (i <- 0 until c.nPoints) {
      poke(c.io.xs(i), x(i))
      poke(c.io.ys(i), y(i))
      poke(c.io.cent(i), cen(i))
    }
    for (i <- 0 until c.nCentroids) {
      val den = cen.filter(_ == i).length

      val centX =
        if (den <= 0.0) 0.0
        else x.zip(cen).filter(_._2 == i).map(_._1).sum / den

      val centY =
        if (den <= 0.0) 0.0
        else y.zip(cen).filter(_._2 == i).map(_._1).sum / den

      expect(c.io.centroidXs(i), centX)
      expect(c.io.centroidYs(i), centY)
    }

    step(1)
  }
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

    val res = check1.clone

    for (i <- 0 until a.nCentroids)
      check1 -= kstep(i)

    expect(check1.length == 0, "CHECK -> \n"+ check1 + "\n" + kstep + "\n" + res)

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
