package eu.unicredit.aparapi

import scala.io.Source
import org.json4s._
import org.json4s.jackson.JsonMethods._


object EntryScala extends App {
  def readPoints(path: String) = {
    val json = Source.fromFile(path).mkString
    implicit val formats = DefaultFormats

    parse(json).extract[List[List[Double]]] map { case List(a, b) => (a, b) }
  }

  val iterations = 1//00
  val points = readPoints("../points.json")
  val xs_x = points.map(_._1.toFloat).toArray
  val xs_y = points.map(_._2.toFloat).toArray
  val start = System.currentTimeMillis
  for (i <- 1 to iterations) {
    Algo.run(xs_x, xs_y)
    //Algo.run2(xs_x, xs_y)
  }
  val time = (System.currentTimeMillis - start) / iterations

  println(s"Made $iterations iterations with an average of $time milliseconds")
}