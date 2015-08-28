package eu.unicredit.kmeans

import Chisel._

case class IntToDblConversionOp(max: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val in = UInt(INPUT, width = 32)
    val out = Dbl(OUTPUT)
  }
  val values =
    Vec {for (i <- 0 to max) yield
      Dbl(i)}

  io.out := values(io.in)
}

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

case class DistanceOp() extends Module with ImplicitInt {
  val io = new Bundle {
    val p1x = Dbl(INPUT)
    val p1y = Dbl(INPUT)
    val p2x = Dbl(INPUT)
    val p2y = Dbl(INPUT)

    val out = Dbl(OUTPUT)
  }

  val po1 = Module(PointOps())
  val po2 = Module(PointOps())

  po1.io.p1x <> io.p1x
  po1.io.p1y <> io.p1y
  po1.io.p2x <> io.p2x
  po1.io.p2y <> io.p2y

  po1.io.operation := 2

  po2.io.p1x <> po1.io.poutx
  po2.io.p1y <> po1.io.pouty

  po2.io.operation := 4

  io.out <> po2.io.out
}



case class Min2Op(i: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val value = Dbl(INPUT)
    val oldMin = UInt(INPUT, width = 32)
    val oldValue = Dbl(INPUT)

    val newMin = UInt(OUTPUT, width = 32)
    val newValue = Dbl(OUTPUT)
  }

  when (io.value >= io.oldValue) {
    io.newMin := io.oldMin
    io.newValue := io.oldValue
  } .otherwise {
    io.newMin := UInt(i)
    io.newValue := io.value
  }
}

case class MinOp(n: Int) extends Module with ImplicitInt {
    val io = new Bundle {
      val values = Vec.fill(n)(Dbl(INPUT))

      val out = UInt(OUTPUT, width = 32)
    }

    val m2s =
      for (i <- 0 until n-1) yield {
        Module(Min2Op(i+1))
      }

    m2s(0).io.oldValue := io.values(0)
    m2s(0).io.oldMin := UInt(0)

    m2s(0).io.value := io.values(1)
    for (i <- 1 until n-1) {
      m2s(i).io.value <> io.values(i+1)
      m2s(i).io.oldValue <> m2s(i-1).io.newValue
      m2s(i).io.oldMin <> m2s(i-1).io.newMin
    }

    io.out := m2s(n-2).io.newMin
}

case class ClosestOp(n: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val pointX = Dbl(INPUT)
    val pointY = Dbl(INPUT)

    val xs = Vec.fill(n)(Dbl(INPUT))
    val ys = Vec.fill(n)(Dbl(INPUT))

    val closest = UInt(OUTPUT, width = 32)
  }
  val po =
    for (i <- 0 until n) yield {
      Module(DistanceOp())
    }

  val mo = Module(MinOp(n))

  for (i <- 0 until n) yield {
    po(i).io.p1x := io.pointX
    po(i).io.p1y := io.pointY

    po(i).io.p2x := io.xs(i)
    po(i).io.p2y := io.ys(i)

    mo.io.values(i) := po(i).io.out
  }

  io.closest := mo.io.out

}

case class CalcCentroidsOp(nPoints: Int, nCentroids: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val centroidsXs = Vec.fill(nCentroids)(Dbl(INPUT))
    val centroidsYs = Vec.fill(nCentroids)(Dbl(INPUT))

    val xs = Vec.fill(nPoints)(Dbl(INPUT))
    val ys = Vec.fill(nPoints)(Dbl(INPUT))

    val out = Vec.fill(nPoints)(UInt(OUTPUT, width = 32))
  }

  val cOps =
    for (_ <- 0 until nPoints) yield
      Module(ClosestOp(nCentroids))

  for (i <- 0 until nPoints) {

    cOps(i).io.pointX <> io.xs(i)
    cOps(i).io.pointY <> io.ys(i)

    for (k <- 0 until nCentroids) {
      cOps(i).io.xs(k) <> io.centroidsXs(k)
      cOps(i).io.ys(k) <> io.centroidsYs(k)
    }

    io.out(i) <> cOps(i).io.closest
  }
}

case class CalcNewCentroidsOp(nPoints: Int, nCentroids: Int) extends Module with ImplicitInt {
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
    Module(CalcNewCentroidsOp(nPoints, nCentroids))

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
