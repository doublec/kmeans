package eu.unicredit.aparapi

import com.amd.aparapi.Kernel
import com.amd.aparapi.Range
import com.amd.aparapi.device.Device

object Algo {
	val n = 10
	val iters = 15

	val cloker = new ClosestKernel()

	val newcker = new NewCentroidsKernel()

	newcker.setCentroids(n)

	def run(xs_x: Array[Float], xs_y : Array[Float]) = {
		val xs_n = xs_x.length
	
		var centroids_x = xs_x take n
		var centroids_y = xs_y take n

		cloker.setXs(xs_x, xs_y)
		newcker.setXs(xs_x, xs_y)

		for (i <- 0 until iters) {

			cloker.setCentroids(centroids_x, centroids_y)

			cloker.execute(xs_n)

			val cents = cloker.out

			newcker.setCents(cents)

			newcker.execute(n)

			centroids_x = newcker.centroids_x
			centroids_y = newcker.centroids_y
		}

		println("Final centroids \n"+centroids_x.zip(centroids_y).mkString("[", ",\n","]"))
	}

}