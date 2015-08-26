package eu.unicredit.kmeans

import Chisel._
import scala.util.Random
import scala.math.sqrt

case class AverageOpTests(a: AverageOp) extends Tester(a) {

  for (_ <- 1 to 10) {
    val values =
      for (i <- 0 until a.n) yield
        Point(Random.nextDouble(), Random.nextDouble())

      for (i <- 0 until a.n) {
        poke(a.io.xs(i), values(i)._x)
        poke(a.io.ys(i), values(i)._y)
      }

      val res = values.reduce(_ + _) / Dbl(a.n)

      expect(a.io.outX, res._x)
      expect(a.io.outY, res._y)
      step(1)
  }
}

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
  for { i <- 1 until c.n} {
    val x = Random.nextDouble
    val y = Random.nextDouble

    poke(c.io.xs(i), x)
    poke(c.io.ys(i), y)

    def sq(x: Double) = x * x
    val dist = sqrt(sq(pointX - x) + sq(pointY - y))

    if (dist < min) {
      min = dist
      minIndex = i
    }
  }

  expect(c.io.closest, minIndex)
  step(1)
}
}
