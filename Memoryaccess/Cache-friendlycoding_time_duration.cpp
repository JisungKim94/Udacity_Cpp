#include <chrono>
#include <iostream>

int main() {
  // create array
  const int size = 4;
  static int x[size][size];

  auto t1 = std::chrono::high_resolution_clock::now();

  // temporal locality is applied.
  // x[j][i] : spatial locality is not applied!
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      // x[i][j] = i + j;
      x[j][i] = i + j;
      // When we interchange the indices i and j when accessing the array as
      // 0x6021e0, 0x6021f0, 0x602100, 0x602110 ...

      //  if commentout below cout code we can't measure duration with
      //  microsecond so, i have to change macro -> nano or increase array x's
      //  size
      // std::cout << &x[i][j] << ": i=" << i << ", j=" << j << std::endl;
      std::cout << &x[j][i] << ": i=" << i << ", j=" << j << std::endl;
    }
  }

  // print execution time to console
  auto t2 = std::chrono::high_resolution_clock::now(); // stop time measurement
  auto duration =
      // std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
      // std::cout << "Execution time: " << duration << " microseconds" <<
      // std::endl;

      std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
  std::cout << "Execution time: " << duration << " nanoseconds" << std::endl;

  return 0;
}