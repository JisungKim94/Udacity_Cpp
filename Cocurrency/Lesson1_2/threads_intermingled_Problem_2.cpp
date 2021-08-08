#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

/* std::this_thread::sleep_for(std::chrono::milliseconds())를 이용해서 thread
 * 실행 순서를 조절. 좋은 방법인지는 모르겠다. for문이 실행되는 시간이 wait for
 * certain amount of time 시간보다 길면 여전히 thread 순서 뒤죽박죽 된다
 * std::chrono::milliseconds(10 * i)줄여서 여러번 보면 알 수 있음 */

int main() {
  // create threads
  std::vector<std::thread> threads;
  for (size_t i = 0; i < 10; ++i) {
    // create new thread from a Lambda
    threads.emplace_back([i]() {
      // wait for certain amount of time
      std::this_thread::sleep_for(std::chrono::milliseconds(1 * i));

      // perform work
      std::cout << "Hello from Worker thread #" << i << std::endl;
    });
  }

  // do something in main()
  std::cout << "Hello from Main thread" << std::endl;

  // call join on all thread objects using a range-based loop
  for (auto &t : threads)
    t.join();

  return 0;
}
