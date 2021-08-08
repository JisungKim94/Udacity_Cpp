#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

/* case1. int nLoops = 1e7, nThreads = 5, std::launch::async : 48.8ms (비동기,
 * pararrellization)
 */
/* case2. int nLoops = 1e7, nThreads = 5, std::launch::deferred : 106ms (동기,
 * 순차적 계산)
 * 비동기 계산이 약 2배 더 빠르다.*/

/* case3. int nLoops = 10, nThreads = 5, std::launch::async : 6ms (비동기,
 * pararrellization) */
/* case4. int nLoops = 10, nThreads = 5, std::launch::deferred : 0.2ms (동기,
 * 순차적 계산)
 * 동기 계산이 약 300배 더 빠르다.*/

/* Conclution : Make Thread is really expensive so, parrallelizaition으로 얻는
 * 이득보다 Thread 생성에 의한 손해가 클 수 있다. 계산량이 무지하게 많은게
 * 아니면 걍 순차적 계산이 더 빠르당*/

void workerFunction(int n) {
  // print system id of worker thread
  std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

  // perform work
  for (int i = 0; i < n; ++i) {
    sqrt(12345.6789);
  }
}

int main() {
  // print system id of worker thread
  std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

  // start time measurement
  std::chrono::high_resolution_clock::time_point t1 =
      std::chrono::high_resolution_clock::now();

  // launch various tasks
  std::vector<std::future<void>> futures;
  int nLoops = 1e6, nThreads = 5;
  for (int i = 0; i < nThreads; ++i) {
    futures.emplace_back(
        std::async(std::launch::deferred, workerFunction, nLoops));
  }

  // wait for tasks to complete
  for (const std::future<void> &ftr : futures)
    ftr.wait();

  // stop time measurement and print execution time
  std::chrono::high_resolution_clock::time_point t2 =
      std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << "Execution finished after " << duration << " microseconds"
            << std::endl;

  return 0;
}