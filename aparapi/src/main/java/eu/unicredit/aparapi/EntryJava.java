package eu.unicredit.aparapi;

import java.io.File;

import com.fasterxml.jackson.core.JsonFactory;
import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.core.JsonToken;

public class EntryJava {

	static int times = 1;//00;

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
				} catch(Exception ex) {
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
		for (int k=0;k<times;k++) {
			kmeans.run();
		}
		long timeAfter = System.currentTimeMillis();
		totalTime = timeAfter -timeBefore;
		System.out.println("Average time "+(totalTime/times));
	}

}