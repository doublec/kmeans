package eu.unicredit.aparapi;

import com.amd.aparapi.Kernel;

public class ClosestKernel extends Kernel {

    float[] xs_x;
    float[] xs_y;
    float[] centroids_x;
    float[] centroids_y;

    int[] out;

    public void setXs(
        float[] xs_x, 
        float[] xs_y) {
      this.xs_x = xs_x;
      this.xs_y = xs_y;
      this.out = new int[xs_x.length];
    } 

    public void setCentroids(
        float[] centroids_x, 
        float[] centroids_y) {
      this.centroids_x = centroids_x;
      this.centroids_y = centroids_y;
    }

    public float dist(int xs_i, int c_i) {
      float x = xs_x[xs_i] - centroids_x[c_i];
      float y = xs_y[xs_i] - centroids_y[c_i];
      return sqrt(pow(x, 2) + pow(y, 2));
    }

    @Override
    public void run() {
      int i = getGlobalId();
      
      int minIndex = 0;
      float minDist = dist(i, 0);

      float dist = minDist;
      for (int k=1; k < centroids_x.length; k++) {
        dist = dist(i, k);
        if (dist < minDist) {
          minDist = dist;
          minIndex = k;
        }
      }
      out[i] = minIndex;
    }
}
