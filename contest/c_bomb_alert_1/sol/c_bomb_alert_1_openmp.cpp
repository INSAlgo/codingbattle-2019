#include <iostream>
#include <math.h>
#include <string>
#include <vector>

/* OpenMP version of the solution for exercise C.
 * Compile with -fopenmp
 *
 * Speedup: proportional to your number of cores on the computation part but
 * the input parsing is still the longest part and we can't speedup this part
 */

using namespace std;

inline float euclidean_distance(float x1, float y1, float x2, float y2) {
  float xd = x1 - x2, yd = y1 - y2;
  return sqrt(xd * xd + yd * yd);
}

int main(int argc, char *argv[]) {
  int n_sus, n_pos;
  float xb, yb;

  std::cin >> xb >> yb >> n_sus >> n_pos;

  // Parse input
  std::vector<float> x = std::vector<float>(n_sus * n_pos);
  std::vector<float> y = std::vector<float>(n_sus * n_pos);
  std::vector<std::string> names = std::vector<std::string>(n_sus);
  for (int i = 0; i < n_sus; i++) {
    std::cin >> names[i];
    for (int j = i * n_pos; j < (i + 1) * n_pos; j++) {
      std::cin >> x[j] >> y[j];
    }
  }

  // Compute suspects
  std::vector<bool> res = std::vector<bool>(n_sus, false);
#pragma omp parallel for
  for (int i = 0; i < n_sus; i++) {
    int offset = i * n_pos;
    for (int j = 0; j < n_pos - 1; j++) {
      float dist =
          euclidean_distance(x[offset + j], y[offset + j], xb, yb) +
          euclidean_distance(x[offset + j + 1], y[offset + j + 1], xb, yb);
      if (dist <= 100.0) {
        res[i] = true;
        break;
      }
    }
  }

  // Output results
  for (int i = 0; i < n_sus; i++) {
    if (res[i])
      std::cout << names[i] << (i < n_sus ? " " : "");
  }
  std::cout << std::endl;

  return 0;
}
