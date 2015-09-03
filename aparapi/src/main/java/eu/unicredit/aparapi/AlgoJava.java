package eu.unicredit.aparapi;

public class AlgoJava {

	int n = 10;
	int iters = 15;

	ClosestKernel cloker = new ClosestKernel();

	NewCentroidsKernel newcker = new NewCentroidsKernel();

	int xs_n;

	float[] centroids_x = new float[n];
	float[] centroids_y = new float[n]; 


	public AlgoJava(float[] xs_x, float[] xs_y) {
		newcker.setCentroids(n);
		cloker.setXs(xs_x, xs_y);
		newcker.setXs(xs_x, xs_y);

		xs_n = xs_x.length;
		for (int i=0; i < n; i++) {
			centroids_x[i] = xs_x[i];
			centroids_y[i] = xs_y[i];
		}
	}


	public void run() {

		for (int i=0; i < iters; i++) {

			cloker.setCentroids(centroids_x, centroids_y);

			cloker.execute(xs_n);

			int[] cents = cloker.out;

			newcker.setCents(cents);

			newcker.execute(n);

			centroids_x = newcker.centroids_x;
			centroids_y = newcker.centroids_y;
			/*for (int c=0; c < n; c++) {
				centroids_x[c] = newcker.centroids_x[c];
				centroids_x[c] = newcker.centroids_x[c];
			}*/
		}

		System.out.println("Final centroids [");
		for (int i = 0 ; i < n; i++) {
			System.out.print(centroids_x[i] +", "+centroids_y[i]+"\n");
		}
		System.out.println("]");
	}
}
