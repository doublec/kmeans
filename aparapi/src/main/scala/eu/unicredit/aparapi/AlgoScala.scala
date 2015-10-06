package eu.unicredit.aparapi

import com.amd.aparapi.Kernel
import com.amd.aparapi.Range

class AlgoScala(xs_x: Array[Float], xs_y : Array[Float]) {
	val n = 10
	val iters = 15

	val range = KmeansKernel.createRange(xs_x.length)
	val kmker = new KmeansKernel(range, xs_x, xs_y, n)

    var centroids_x: Array[Float] = null
    var centroids_y: Array[Float] = null

	def run = {
		kmker.execute(range, 2*iters+1)
		centroids_x = kmker.centroids_x
		centroids_y = kmker.centroids_y
	}
}