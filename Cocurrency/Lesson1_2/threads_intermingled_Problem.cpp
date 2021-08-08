#include <iostream>
#include <thread>
#include <vector>

/* The order in which threads are executed is non-deterministic. Every time a
 * program is executed, there is a chance for a completely different order of
 * execution.
 * 실행 결과를 보면 main이랑 다른 thread들이랑 순서가 지맘대로임...
 * 쓰래드는 어떤 쓰레드1이 실행될 때 다른 쓰레드2의 실행이 될 수 있다.
 * 즉 순서가 뒤죽박죽이 될 수 있음.. 이런 문제는 뭐 1000개의 쓰래드가 돌아가고
 * 있는데 하나가 순서가 섞였다? 디버깅 하기 쥰내 힘들어 지는거*/

void printHello() {
  // perform work
  std::cout << "Hello from Worker thread #" << std::this_thread::get_id()
            << std::endl;
}

int main() {
  // create threads
  std::vector<std::thread> threads;
  for (size_t i = 0; i < 5; ++i) {
    // copying thread objects causes a compile error

    //         std::thread t(printHello);
    //         threads.push_back(t);

    // moving thread objects will work
    threads.emplace_back(std::thread(printHello));
  }

  // do something in main()
  std::cout << "Hello from Main thread #" << std::this_thread::get_id()
            << std::endl;

  // call join on all thread objects using a range-based loop
  for (auto &t : threads)
    t.join();

  return 0;
}
