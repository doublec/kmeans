package eu.unicredit.kmeans

import Chisel._

trait PointOpsHelpers {
  self: Tester[PointOps] =>

  val tester = self

  final val CLEAR = 0
  final val ADD = 1
  final val SUB = 2
  final val DIV = 3
  final val MOD = 4

  private var inner: Point = Point(0.0, 0.0)

  def step: Unit = tester.step(1)

  implicit class PointOpsHelper(po: PointOps) {

    def set(p: Point) = {
      tester.poke(po.io.p1x, p._x)
      tester.poke(po.io.p1y, p._y)

      inner = p
    }

    def clear() = {
      tester.poke(po.io.operation, CLEAR)

      val empty = Point(0.0, 0.0)
      tester.expect(po.io.poutx, empty._x)
      tester.expect(po.io.pouty, empty._y)

      set(empty)
    }

    private def op(num: Int, f: (Point, Point) => Point)(p2: Point) = {
      tester.poke(po.io.p2x, p2._x)
      tester.poke(po.io.p2y, p2._y)

      tester.poke(po.io.operation, num)

      val res = f(inner, p2)
      tester.expect(po.io.poutx, res._x)
      tester.expect(po.io.pouty, res._y)

      set(res)
    }

    private def op(num: Int, f: (Point, Double) => Point)(d: Double) = {
      tester.poke(po.io.den, d)

      tester.poke(po.io.operation, num)

      val res = f(inner, d)
      tester.expect(po.io.poutx, res._x)
      tester.expect(po.io.pouty, res._y)

      set(res)
    }

    val +  = op(ADD, (x: Point, y: Point) => x+y) _

    val - = op(SUB, (x: Point, y: Point) => x-y) _

    val / = op(DIV, (x: Point, d: Double) => x/Dbl(d)) _

    val modulus = {
      import scala.math.sqrt
      val mod = sqrt(inner._x*inner._x + inner._y*inner._y)

      tester.poke(po.io.operation, MOD)

      tester.expect(po.io.out, mod)
    }
  }
}

case class PointOpsTests(p: PointOps) extends Tester(p) with PointOpsHelpers {

  p clear

  p set Point(1, 1)

  step

  p + Point(2, 2)

  step

  p clear

  step

  p + Point(3, 3)

  step

  p + Point(6, 8)

  step

  p - Point(5, 7)

  step

  p / 2

  step

  p modulus

  step

}
