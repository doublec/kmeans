package eu.unicredit.aparapi;

import java.io.File;

import com.fasterxml.jackson.core.JsonFactory;
import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.core.JsonToken;

public class EntryJava {

	// benchmark's final centroids
	static double[][] bench = {
		{1.918441639829494, 2.2623855839482294},
		{2.47790984305693, 1.945630722483613},
		{0.8322035175020596, 1.6266582764165047},
		{1.5309869001400929, 0.7852174204702566},
		{1.0084564757347625, 2.2868123889219047},
		{1.6894738051930507, 1.7278381134195009},
		{2.035067805355936, 0.36068184317747537},
		{2.2019938378105004, 1.3767916116287988},
		{2.316742530156974, 2.8586899252009443},
		{1.4688362327217774, 0.2078953628686833}
	};

	static int times = 100;

	public static void main(String[] args) throws Exception {
		JsonFactory factory = new JsonFactory();
		JsonParser jp = factory.createJsonParser(new File("../points.json"));

		float[] xs_x = new float[100000];
		float[] xs_y = new float[100000];
		int i = 0;
		while (true) {
			JsonToken actual = jp.nextValue();
			while (actual == JsonToken.START_ARRAY) {
				actual = jp.nextValue();
			}
			try {
				double x = jp.getDoubleValue();
				jp.nextToken();
				double y = jp.getDoubleValue();
				xs_x[i] = (float) x;
				xs_y[i] = (float) y;
				i++;
			} catch (Exception ex) {
				//ex.printStackTrace();
				break;
			}
			actual = jp.nextToken();
			while (jp.nextToken() == JsonToken.END_ARRAY) {
				actual = jp.nextToken();
			}
		}
		jp.close();

		AlgoJava kmeans = new AlgoJava(xs_x, xs_y);
		long totalTime = 0;
		long timeBefore = System.currentTimeMillis();
		for (int k = 0; k < times; k++) {
			kmeans.run();
		}
		long timeAfter = System.currentTimeMillis();
		totalTime = timeAfter - timeBefore;
		System.out.println("Average time " + (totalTime / times));

		System.out.println("Final centroids [");
		for (int j = 0 ; j < kmeans.n; j++) {
			System.out.println(kmeans.centroids_x[j] + ", " + kmeans.centroids_y[j]);
		}
		System.out.println("]");
		System.out.println("Difference with benchmark's centroids");
		for (int j = 0 ; j < kmeans.n; j++) {
			System.out.printf("%.10f - %.10f\n", (kmeans.centroids_x[j] - bench[j][0]), (kmeans.centroids_y[j] - bench[j][1]));
		}
	}

}