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

case class LimitedAverageOpTests(a: LimitedAverageOp) extends Tester(a) {
/*
  val values =
    for (i <- 0 until a.n) yield
      Point(0.0+i, 0.0+i)
    val limit = 3
    poke(a.io.limit, limit)

    for (i <- 0 until a.n) {
      poke(a.io.xs(i), values(i)._x)
      poke(a.io.ys(i), values(i)._y)
    }

    val res =
      if (limit > 0)
        values.take(limit).reduce(_ + _) / Dbl(limit)
      else Point(0.0, 0.0)

    expect(a.io.outX, res._x)
    expect(a.io.outY, res._y)
    step(1)
*/

  for (_ <- 1 to 10) {
    val values =
      for (i <- 0 until a.n) yield
        Point(Random.nextDouble(), Random.nextDouble())

      val limit = Random.nextInt(a.n+1)
      poke(a.io.limit, limit)

      for (i <- 0 until a.n) {
        poke(a.io.xs(i), values(i)._x)
        poke(a.io.ys(i), values(i)._y)
      }

      val res =
        if (limit > 0)
          values.take(limit).reduce(_ + _) / Dbl(limit)
        else Point(0.0, 0.0)

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

case class OffsetGeneratorOpTests(o: OffsetGeneratorOp) extends Tester(o) {
//to be more exaustive
  poke(o.io.in(0), 0)
  poke(o.io.in(1), 1)
  poke(o.io.in(2), 2)
  poke(o.io.in(3), 2)
  poke(o.io.in(4), 2)
  poke(o.io.in(5), 1)

  expect(o.io.out(0), 0)
  expect(o.io.out(1), 0)
  expect(o.io.out(2), 0)
  expect(o.io.out(3), 1)
  expect(o.io.out(4), 2)
  expect(o.io.out(5), 1)

  step(1)
}

case class BoolSelectorOpTests(b: BoolInSelectorOp) extends Tester(b) {
  poke(b.io.in1, 1.0)
  poke(b.io.in2, 2.0)
  poke(b.io.valid1, true)

  expect(b.io.out, 1.0)

  step(1)

  poke(b.io.in1, 3.0)
  poke(b.io.in2, 4.0)
  poke(b.io.valid1, false)

  expect(b.io.out, 4.0)

}

case class MultiInSelectorOpTests(m: MultiInSelectorOp) extends Tester(m) {
  poke(m.io.in(0), 1.0)
  poke(m.io.in(1), 2.0)
  poke(m.io.in(2), 3.0)
  poke(m.io.in(3), 4.0)
  poke(m.io.in(4), 5.0)
  poke(m.io.select, 3)

  expect(m.io.out, 4.0)

  step(1)

  poke(m.io.select, 0)

  expect(m.io.out, 1.0)

  step(1)

  poke(m.io.select, 4)

  expect(m.io.out, 5.0)
}

case class CalcNewCentroidsOpTests(c: CalcNewCentroidsOp) extends Tester(c) {
  /*
  val x =
    for (_ <- 1 to c.nPoints) yield Random.nextDouble

  val y =
    for (_ <- 1 to c.nPoints) yield Random.nextDouble

  val cen =
    for (_ <- 1 to c.nPoints) yield Random.nextInt(c.nCentroids+1)

  for (i <- 0 until c.nPoints) {
    poke(c.io.xs(i), x(i))
    poke(c.io.ys(i), y(i))
    poke(c.io.cent(i), 0)
  }
  for (i <- 0 until c.nCentroids) {
    expect(c.io.centroidXs(0), x.zip(cen).filter(_._2 == i).map(_._1).sum / cen.filter(_._2 == i).size)
    expect(c.io.centroidYs(0), y.zip(cen).filter(_._2 == i).map(_._1).sum / cen.filter(_._2 == i).size)
  }

  step(1)
*/
poke(c.io.xs(0), 1.0)
poke(c.io.ys(0), 1.0)
poke(c.io.cent(0), 0)

poke(c.io.xs(1), 2.0)
poke(c.io.ys(1), 2.0)
poke(c.io.cent(1), 0)

expect(c.io.centroidXs(0), 1.5)
expect(c.io.centroidYs(0), 1.5)
expect(c.io.centroidXs(1), 0.0)
expect(c.io.centroidYs(1), 0.0)

step(1)

poke(c.io.xs(0), 1.0)
poke(c.io.ys(0), 1.0)
poke(c.io.cent(0), 1)

poke(c.io.xs(1), 2.0)
poke(c.io.ys(1), 2.0)
poke(c.io.cent(1), 0)

expect(c.io.centroidXs(0), 1.0)
expect(c.io.centroidYs(0), 1.0)
expect(c.io.centroidXs(1), 2.0)
expect(c.io.centroidYs(1), 2.0)

step(1)

  /*
  poke(c.io.xs(0), 1.0)
  poke(c.io.ys(0), 1.0)
  poke(c.io.cent(0), 0)

  poke(c.io.xs(1), 2.0)
  poke(c.io.ys(1), 2.0)
  poke(c.io.cent(1), 0)

  poke(c.io.xs(2), 3.0)
  poke(c.io.ys(2), 3.0)
  poke(c.io.cent(2), 0)

  expect(c.io.centroidXs(0), 2.0)
  expect(c.io.centroidYs(0), 2.0)
  expect(c.io.centroidXs(1), 0.0)
  expect(c.io.centroidYs(1), 0.0)

  step(1)

  poke(c.io.xs(0), 1.0)
  poke(c.io.ys(0), 1.0)
  poke(c.io.cent(0), 0)

  poke(c.io.xs(1), 2.0)
  poke(c.io.ys(1), 2.0)
  poke(c.io.cent(1), 0)

  poke(c.io.xs(2), 3.0)
  poke(c.io.ys(2), 3.0)
  poke(c.io.cent(2), 1)

  expect(c.io.centroidXs(0), 1.5)
  expect(c.io.centroidYs(0), 1.5)
  expect(c.io.centroidXs(1), 3.0)
  expect(c.io.centroidYs(1), 3.0)

  step(1)

//c'è un errore 'azz'
  poke(c.io.xs(0), 1.0)
  poke(c.io.ys(0), 1.0)
  poke(c.io.cent(0), 0)

  poke(c.io.xs(1), 2.0)
  poke(c.io.ys(1), 2.0)
  poke(c.io.cent(1), 1)

  poke(c.io.xs(2), 3.0)
  poke(c.io.ys(2), 3.0)
  poke(c.io.cent(2), 1)

  expect(c.io.centroidXs(0), 1.0)
  expect(c.io.centroidYs(0), 1.0)
  expect(c.io.centroidXs(1), 2.5)
  expect(c.io.centroidYs(1), 2.5)

  step(1)
  */
}
