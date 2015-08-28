package eu.unicredit.kmeans

import Chisel._

case class AverageOp(n: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val xs = Vec.fill(n)(Dbl(INPUT))
    val ys = Vec.fill(n)(Dbl(INPUT))

    val outX = Dbl(OUTPUT)
    val outY = Dbl(OUTPUT)
  }

  val po =
    for (i <- 0 to n) yield {
      Module(PointOps())
    }

  po(0).io.p1x := Dbl(0.0)
  po(0).io.p1y := Dbl(0.0)

  po(0).io.p2x := io.xs(0)
  po(0).io.p2y := io.ys(0)

  po(0).io.operation := 1

  for (i <- 1 until n) yield {
    po(i).io.p2x <> io.xs(i)
    po(i).io.p2y <> io.ys(i)

    po(i).io.p1x <> po(i-1).io.poutx
    po(i).io.p1y <> po(i-1).io.pouty

    po(i).io.operation := 1
  }

  po(n).io.p1x <> po(n-1).io.poutx
  po(n).io.p1y <> po(n-1).io.pouty

  po(n).io.den := Dbl(n)

  po(n).io.operation := 3

  io.outX <> po(n).io.poutx
  io.outY <> po(n).io.pouty
}

case class LimitedPointOps() extends Module with ImplicitInt {
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
    val count = UInt(INPUT, width = 32)
    val limit = UInt(INPUT, width = 32)
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
  when (io.count > io.limit && io.operation === UInt(1)) {
    io.poutx := io.p1x
    io.pouty := io.p1y
  }
}

case class LimitedAverageOp(n: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val xs = Vec.fill(n)(Dbl(INPUT))
    val ys = Vec.fill(n)(Dbl(INPUT))

    val limit = UInt(INPUT, width = 32)

    val outX = Dbl(OUTPUT)
    val outY = Dbl(OUTPUT)
  }

  val po =
    for (i <- 0 to n) yield {
      Module(LimitedPointOps())
    }

  po(0).io.p1x := Dbl(0.0)
  po(0).io.p1y := Dbl(0.0)

  po(0).io.p2x := io.xs(0)
  po(0).io.p2y := io.ys(0)

  po(0).io.limit := io.limit
  po(0).io.count := UInt(0)

  po(0).io.operation := 1

  for (i <- 1 until n) yield {
    po(i).io.p2x <> io.xs(i)
    po(i).io.p2y <> io.ys(i)

    po(i).io.p1x <> po(i-1).io.poutx
    po(i).io.p1y <> po(i-1).io.pouty

    po(i).io.operation := 1

    po(i).io.limit := io.limit
    po(i).io.count := UInt(i+1)
  }

  po(n).io.p1x <> po(n-1).io.poutx
  po(n).io.p1y <> po(n-1).io.pouty

  val conv = Module(IntToDblConversionOp(n))
  conv.io.in <> io.limit
  po(n).io.den <> conv.io.out

  po(n).io.operation := 3

  io.outX := po(n).io.poutx
  io.outY := po(n).io.pouty
  when (io.limit <= UInt(0)) {
    io.outX := Dbl(0.0)
    io.outY := Dbl(0.0)
  }
}

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

case class DistanceOp(i: Int) extends Module with ImplicitInt {
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
      Module(DistanceOp(i))
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

case class OffsetGeneratorOp(nPoints: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val in = Vec.fill(nPoints)(UInt(INPUT, width = 32))
    val out = Vec.fill(nPoints)(UInt(OUTPUT, width = 32))
  }

  val counts =
    for (c <- 0 until nPoints) yield {
      Vec{for (x <- 0 until c) yield io.in(x)}.count{ x: UInt => x === io.in(c)}
    }

  for (c <- 0 until nPoints) yield
    io.out(c) := counts(c)
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
      Module(LimitedAverageOp(nPoints))
    }

  val offsets =
    Module(OffsetGeneratorOp(nPoints))

  for (i <- 0 until nPoints) {
    offsets.io.in(i) <> io.cent(i)
  }

  val limits =
    for (i <- 0 until nCentroids) yield {
      io.cent.count{x: UInt => x === UInt(i)}
    }

  for (k <- 0 until nCentroids) {
    avgs(k).io.limit := limits(k)
  }

  //da rivedere la parte dei selectors...sbagliano da qualche parte con multipli centroidi
  //di base probabilmente manca l'N output fillato da zeri
  val selectorsX =
    (for (ip <- 0 until nPoints) yield
      for (ic <- 0 until nCentroids) yield
        Module(MultiInSelectorOp(nPoints))).flatten

  val selectorsY =
    (for (ip <- 0 until nPoints) yield
      for (ic <- 0 until nCentroids) yield
        Module(MultiInSelectorOp(nPoints))).flatten

  val selectorPX =
    for (ic <- 0 until nPoints) yield
      Module(MultiInSelectorOp(nCentroids))

  val selectorPY =
    for (ic <- 0 until nPoints) yield
      Module(MultiInSelectorOp(nCentroids))

  for (ip <- 0 until nPoints) {
    for (ic <- 0 until nCentroids) {
      selectorPX(ip).io.in(ic) <> selectorsX(ip + (ic * nPoints)).io.out
      selectorPY(ip).io.in(ic) <> selectorsY(ip + (ic * nPoints)).io.out
      avgs(ic).io.xs(ip) <> selectorPX(ip).io.out//selectorsX(ip + (ic * nPoints)).io.out
      avgs(ic).io.ys(ip) <> selectorPX(ip).io.out//selectorsY(ip + (ic * nPoints)).io.out
    }
  }

  for (ip <- 0 until nPoints) {
    selectorPX(ip).io.select := io.cent(ip)
    selectorPY(ip).io.select := io.cent(ip)
    for (ic <- 0 until nCentroids) {
      selectorsX(ip + (ic * nPoints)).io.in(ip) <> io.xs(ip)
      selectorsX(ip + (ic * nPoints)).io.select := /*((io.cent(ip) * UInt(nPoints)) +*/ ( offsets.io.out(ip))
      selectorsY(ip + (ic * nPoints)).io.in(ip) <> io.ys(ip)
      selectorsY(ip + (ic * nPoints)).io.select := /*((io.cent(ip) * UInt(nPoints)) +*/ ( offsets.io.out(ip))
    }
  }

  for (k <- 0 until nCentroids) {
    io.centroidXs(k) := avgs(k).io.outX
    io.centroidYs(k) := avgs(k).io.outY
  }
}

case class BoolInSelectorOp() extends Module with ImplicitInt {
  val io = new Bundle {
    val in1 = Dbl(INPUT)
    val in2 = Dbl(INPUT)

    val valid1 = Bool(INPUT)

    val out = Dbl(OUTPUT)
  }

  io.out := io.in1
  when (!io.valid1) {
    io.out := io.in2
  }
}

case class MultiInSelectorOp(inN: Int) extends Module with ImplicitInt {
  val io = new Bundle {
    val in = Vec.fill(inN)(Dbl(INPUT))
    val select = UInt(INPUT, width = 32)
    val out = Dbl(OUTPUT)
  }

  val bs =
    for (_ <- 0 until inN) yield
      Module(BoolInSelectorOp())

  when (UInt(inN) >= UInt(2)) {
    bs(0).io.in1 := io.in(0)
    bs(0).io.in2 := io.in(1)
    bs(0).io.valid1 := (io.select === UInt(0))
    for (i <- 1 until inN) {
      bs(i).io.in2 := io.in(i)
      bs(i).io.in1 := bs(i-1).io.out
      bs(i).io.valid1 := (io.select != UInt(i))
    }
    io.out := bs(inN-1).io.out
  } .elsewhen(UInt(inN) === UInt(1) && io.select === UInt(0)) {
    io.out := io.in(0)
  } .otherwise {
    io.out := Dbl(0.0)
  }
}
