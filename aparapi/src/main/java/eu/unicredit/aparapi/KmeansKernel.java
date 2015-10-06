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

    @Local float[] lc_x;
    @Local float[] lc_y;
    @Local int[] lcount;

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

      lc_x = new float[range.getLocalSize(0)];
      lc_y = new float[range.getLocalSize(0)];
      lcount = new int[range.getLocalSize(0)];
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
        int size = getNumGroups();
        int l = getLocalId();
        int g = getGroupId();
        lc_x[l] = 0.0f;
        lc_y[l] = 0.0f;
        lcount[l] = 0;

        if (g < centroids_x.length) {
          int start = l*size;
          int end = start+size;
          for (int k = start; k < end; k++) {
            if (cents[k] == g) {
              lc_x[l] += xs_x[k];
              lc_y[l] += xs_y[k];
              lcount[l]++;
            }
          } 
        }

        localBarrier();

        if (g < centroids_x.length && l == 0) {
          float x_sum = lc_x[0];
          float y_sum = lc_y[0];
          int count = lcount[0];
          // serial sum of partial results
          for (int k = 1; k < getLocalSize(); k++) {
            x_sum += lc_x[k];
            y_sum += lc_y[k];
            count += lcount[k];
          }
          if (x_sum == 0.0f)
            centroids_x[g] = 0.0f;
          else
            centroids_x[g] = x_sum / count;
  
          if (y_sum == 0.0f)
            centroids_y[g] = 0.0f;
          else
            centroids_y[g] = y_sum / count;
        }
      }
    }
}
