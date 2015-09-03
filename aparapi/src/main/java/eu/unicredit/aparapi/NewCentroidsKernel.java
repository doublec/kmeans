package eu.unicredit.aparapi;

import com.amd.aparapi.Kernel;

public class NewCentroidsKernel extends Kernel {

    float[] xs_x;
    float[] xs_y;
    float[] centroids_x;
    float[] centroids_y;

    int[] cents;

    public void setXs(
        float[] xs_x, 
        float[] xs_y) {
      this.xs_x = xs_x;
      this.xs_y = xs_y;
    }

    public void setCentroids(int n) {
      this.centroids_x = new float[n];
      this.centroids_y = new float[n];
    }

    public void setCents(
        int[] cents) {
      this.cents = cents;
    }

    @Override
    public void run() {
      int i = getGlobalId();
      
      float x_sum = 0;
      float y_sum = 0;
      int count = 0;
      for (int k=0; k < xs_x.length; k++) {
        if (cents[k] == i) {
          count++;
          x_sum = x_sum + xs_x[k];
          y_sum = y_sum + xs_y[k];
        }
      }

      if (x_sum == 0.0f)
        centroids_x[i] = 0.0f;
      else
        centroids_x[i] = x_sum / count;

      if (x_sum == 0.0f)
        centroids_y[i] = 0.0f;
      else
        centroids_y[i] = y_sum / count;
    }
}
