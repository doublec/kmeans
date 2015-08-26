package eu.unicredit.kmeans

import Chisel._

case class PointOps() extends Module with ImplicitInt {
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
  }

  val p1 = Point(io.p1x, io.p1y)
  val p2 = Point(io.p2x, io.p2y)

  //if not initialized null pointer
  io.poutx := Dbl(0.0)
  io.pouty := Dbl(0.0)
  io.out := Dbl(0.0)

  when (io.operation === 0) {
    io.poutx := Dbl(0.0)
    io.pouty := Dbl(0.0)
  } .elsewhen(io.operation === 1) {
    val res = p1 + p2
    io.poutx := res.x
    io.pouty := res.y
  } .elsewhen(io.operation === 2) {
    val res = p1 - p2
    io.poutx := res.x
    io.pouty := res.y
  } .elsewhen(io.operation === 3) {
    val res = p1 / io.den
    io.poutx := res.x
    io.pouty := res.y
  } .elsewhen(io.operation === 4) {
    val res = p1.modulus
    io.out := res
  } .otherwise {
    io.poutx := Dbl(0.0)
    io.pouty := Dbl(0.0)
  }
}

case class Point(x: Dbl, y: Dbl) {
  val _x = java.lang.Double.longBitsToDouble(x.litValue().longValue)
  val _y = java.lang.Double.longBitsToDouble(y.litValue().longValue)

  def +(p2: Point) = Point(x + p2.x, y + p2.y)
  def -(p2: Point) = Point(x - p2.x, y - p2.y)
  def /(den: Dbl) = Point(x / den, y / den)

  private def sq(d: Dbl): Dbl = d * d

  def modulus: Dbl = (sq(x) + sq(y)).sqrt

  //def dist(p2: Point): Dbl = (this - p2).modulus
}

object Point {
  def apply(x: Int, y: Int): Point = new Point(Dbl(x), Dbl(y))
  def apply(x: Long, y: Long): Point = new Point(Dbl(x), Dbl(y))
  def apply(x: Double, y: Double): Point = new Point(Dbl(x), Dbl(y))
  def apply(x: Double, y: Int): Point = new Point(Dbl(x), Dbl(y))
  def apply(x: Int, y: Double): Point = new Point(Dbl(x), Dbl(y))
  def apply(x: Dbl, y: Double): Point = new Point(x, Dbl(y))
  def apply(x: Double, y: Dbl): Point = new Point(Dbl(x), y)
}
