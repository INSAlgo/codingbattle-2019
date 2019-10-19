#include <iostream>
#include <string>
#include <vector>

/* CUDA version of the solution for exercise C.
 * Actually doesn't provide interesting speedups with the given input/output
 * samples because:
 * A- the samples have very small problem dimensions so the overhead of the
 *    first CUDA API call is by far longer than the actual execution
 * B- more time is spent reading the inputs than doing actual computations
 */

/* Helper function to calculate the Euclidean distance between two points
 * on a 2D plane */
inline __device__ float euclidean_distance(float x1, float y1, float x2,
                                           float y2) {
  float xd = x1 - x2, yd = y1 - y2;
  return sqrt(xd * xd + yd * yd);
}

__global__ void suspects_kernel(const float *x, const float *y, bool *results,
                                int n_sus, int n_pos, float xb, float yb) {
  int pos_idx = blockIdx.x * (blockDim.x - 1) + threadIdx.x;
  int sus_idx = blockIdx.y * blockDim.y + threadIdx.y;

  // Load block in shared memory
  __shared__ float x_shared[256];
  __shared__ float y_shared[256];
  {
    int shared_load_idx = threadIdx.y * blockDim.x + threadIdx.x;
    int global_load_idx = sus_idx * n_pos + pos_idx;
    bool do_load = sus_idx < n_sus && pos_idx < n_pos;
    x_shared[shared_load_idx] = do_load ? x[global_load_idx] : 0.0;
    y_shared[shared_load_idx] = do_load ? y[global_load_idx] : 0.0;
  }
  __syncthreads();

  /* Compute the sum of the distances from the position to bomb and the bomb
   * to the next position */
  float dist = 101.0;
  if (sus_idx < n_sus && pos_idx < n_pos - 1 && threadIdx.x < blockDim.x - 1) {
    int shared_idx = threadIdx.y * blockDim.x + threadIdx.x;
    dist =
        euclidean_distance(x_shared[shared_idx], y_shared[shared_idx], xb, yb) +
        euclidean_distance(x_shared[shared_idx + 1], y_shared[shared_idx + 1],
                           xb, yb);
  }
  if (dist <= 100.0)
    results[sus_idx] = true;
}

int main(int argc, char *argv[]) {
  int n_sus, n_pos;
  float xb, yb;

  std::cin >> xb >> yb >> n_sus >> n_pos;

  // Allocate device memory
  float *x_d, *y_d;
  bool *res_d;
  cudaMalloc((void **)&x_d, n_sus * n_pos * sizeof(float));
  cudaMalloc((void **)&y_d, n_sus * n_pos * sizeof(float));
  cudaMalloc((void **)&res_d, n_sus * sizeof(bool));

  // Parse input
  std::vector<float> x_h = std::vector<float>(n_sus * n_pos);
  std::vector<float> y_h = std::vector<float>(n_sus * n_pos);
  std::vector<std::string> names = std::vector<std::string>(n_sus);
  for (int i = 0; i < n_sus; i++) {
    std::cin >> names[i];
    for (int j = i * n_pos; j < (i + 1) * n_pos; j++) {
      std::cin >> x_h[j] >> y_h[j];
    }
  }

  // Transfer data to the device
  cudaMemcpy(x_d, x_h.data(), n_sus * n_pos * sizeof(float),
             cudaMemcpyHostToDevice);
  cudaMemcpy(y_d, y_h.data(), n_sus * n_pos * sizeof(float),
             cudaMemcpyHostToDevice);
  cudaMemset(res_d, 0, n_sus * sizeof(bool));

  /* Launch kernel to compute suspects
   * Note: grid and block dims should be fine-tuned for the problem dimensions
   */
  dim3 block(16, 16, 1);
  dim3 grid((n_pos - 1) / (block.x - 1) + 1, (n_sus - 1) / block.y + 1, 1);
  suspects_kernel<<<grid, block>>>(x_d, y_d, res_d, n_sus, n_pos, xb, yb);

  // Copy results to host
  bool res_h[n_sus];
  cudaMemcpy(res_h, res_d, n_sus * sizeof(bool), cudaMemcpyDeviceToHost);

  // Free device memory
  cudaFree(x_d);
  cudaFree(y_d);
  cudaFree(res_d);

  // Output results
  for (int i = 0; i < n_sus; i++) {
    if (res_h[i])
      std::cout << names[i] << (i < n_sus ? " " : "");
  }
  std::cout << std::endl;

  return 0;
}
