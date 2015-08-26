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
