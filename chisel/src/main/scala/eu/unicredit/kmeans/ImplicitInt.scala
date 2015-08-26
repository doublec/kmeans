package eu.unicredit.kmeans

import Chisel._

trait ImplicitInt {

  implicit def fromIntToUInt(i: Int): UInt = UInt(i)
}
