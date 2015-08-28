package eu.unicredit.kmeans

import Chisel._
import scala.util.Random
import scala.math.sqrt

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

case class CalcNewCentroids2OpTests(c: CalcNewCentroids2Op) extends Tester(c) {

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
/*
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

expect(c.io.centroidXs(0), 2.0)
expect(c.io.centroidYs(0), 2.0)
expect(c.io.centroidXs(1), 1.0)
expect(c.io.centroidYs(1), 1.0)

step(1)

poke(c.io.xs(0), 1.0)
poke(c.io.ys(0), 1.0)
poke(c.io.cent(0), 1)

poke(c.io.xs(1), 2.0)
poke(c.io.ys(1), 2.0)
poke(c.io.cent(1), 1)

expect(c.io.centroidXs(0), 0.0)
expect(c.io.centroidYs(0), 0.0)
expect(c.io.centroidXs(1), 1.5)
expect(c.io.centroidYs(1), 1.5)

step(1)
*/

}
