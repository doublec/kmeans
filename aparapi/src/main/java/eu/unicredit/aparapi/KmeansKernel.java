package eu.unicredit.aparapi;

import com.amd.aparapi.Kernel;
import com.amd.aparapi.Range;
import com.amd.aparapi.device.Device;

public class KmeansKernel extends Kernel {

    float[] xs_x;
    float[] xs_y;
    float[] centroids_x;
    float[] centroids_y;

    int[] cents;

    public static Range createRange(int length) {
      return Range.create(Device.best(), length);
    }

    public KmeansKernel(Range range, float[] xs_x, float[] xs_y, int n) {
      setExplicit(true);
      
      this.xs_x = xs_x;
      this.xs_y = xs_y;
      this.cents = new int[xs_x.length];
      this.centroids_x = new float[n];
      this.centroids_y = new float[n];
    } 

    public float dist(int xs_i, int c_i) {
      float x = xs_x[xs_i] - centroids_x[c_i];
      float y = xs_y[xs_i] - centroids_y[c_i];
      return sqrt(pow(x, 2) + pow(y, 2));
    }

    @Override
    public void run() {
      if (getPassId() == 0) { // step 0
        // init centroids
        int i = getGlobalId();
        if (i < centroids_x.length) {
          centroids_x[i] = xs_x[i];
          centroids_y[i] = xs_y[i];
        }
      }
      else if (getPassId() % 2 == 1) { // odd step
        // closest centroid
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
        cents[i] = minIndex;
      } 
      else if (getPassId() % 2 == 0) { // even step
        // new centroids
        if (getGroupId() < centroids_x.length && getLocalId() == 0) {
          int i = getGroupId();
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

          if (y_sum == 0.0f)
            centroids_y[i] = 0.0f;
          else
            centroids_y[i] = y_sum / count;
        }
      }
    }
}
