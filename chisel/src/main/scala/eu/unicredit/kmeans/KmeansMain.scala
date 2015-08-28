package eu.unicredit.kmeans

import Chisel._

object KmeansMain extends App {

  val argz: Array[String] =
    if (args.isEmpty) {
      println("C test execution")
      Array("--backend", "c", "--genHarness", "--compile", "--test")
    } else if (args.map(_.toString).contains("v")) {
      println("Verilog generation")
      Array("--backend", "v", "--compile", "--test")
    } else {
      println("Unmanaged argument args are "+args.mkString("[",",","]") )
      Array()
    }

  chiselMainTest(argz, () => Module(PointOps())){(p) => PointOpsTests(p)}

  chiselMainTest(argz, () => Module(DistanceOp())){(d) => DistanceOpTests(d)}

  chiselMainTest(argz, () => Module(MinOp(10))){(c) => MinOpTests(c)}

  chiselMainTest(argz, () => Module(Min2Op(9))){(m) => Min2OpTests(m)}

  chiselMainTest(argz, () => Module(ClosestOp(10))){(c) => ClosestOpTests(c)}

  chiselMainTest(argz,() => Module(CalcCentroidsOp(10,3)))(c => CalcCentroidsOpTests(c))

  chiselMainTest(argz,() => Module(SelectiveAverageOp(3,1)))(m => SelectiveAverageOpTests(m))

  chiselMainTest(argz,() => Module(CalcNewCentroidsOp(10,5)))(o => CalcNewCentroidsOpTests(o))

  chiselMainTest(argz,() => Module(Algo(10,4)))(a => AlgoTests(a))
}
