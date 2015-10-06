package eu.unicredit.aparapi;

import com.amd.aparapi.Range;
import com.amd.aparapi.device.Device;

public class AlgoJava {

	int n = 10;
	int iters = 15;

	KmeansKernel kmker;

	int global_width = 100000;
	int local_width = 500;
	Range range;

	float[] centroids_x;
	float[] centroids_y;

	public AlgoJava(float[] xs_x, float[] xs_y) {
		range = KmeansKernel.createRange(xs_x.length);
		kmker = new KmeansKernel(range, xs_x, xs_y, n);
		System.out.println("Best " + Device.best());
		System.out.println("Execution mode: " + kmker.getExecutionMode());
	}

	public void run() {
		kmker.execute(range, 2 * iters + 1);
		centroids_x = kmker.centroids_x;
		centroids_y = kmker.centroids_y;
	}
}
