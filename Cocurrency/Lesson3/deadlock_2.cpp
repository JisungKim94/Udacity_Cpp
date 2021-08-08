#include <iostream>
#include <mutex>
#include <thread>

/* mutex1이랑 mutex2가 서로를 잠가버려서 서로 resource에 접근이 안되고 그래서
 * 끝이 안남
 한가지 해결법은 리소스 접근을 엄격히 증가 혹은 감소 한 방향으로만 하게 하는거
 lock을 지맘대로 하지말고 항상 한 방향으로만 하면 댐 unlock은 상관없는듯..?*/

std::mutex mutex1, mutex2;

void ThreadA() {
  //   // Creates deadlock problem
  //   mutex2.lock();
  //   std::cout << "Thread A" << std::endl;
  //   mutex1.lock();
  //   mutex2.unlock();
  //   mutex1.unlock();

  // Solves deadlock problem
  mutex2.lock();
  std::cout << "Thread A" << std::endl;
  mutex1.lock();
  mutex1.unlock();
  mutex2.unlock();
}

void ThreadB() {
  // Creates deadlock problem
  //   mutex1.lock();
  //   std::cout << "Thread B" << std::endl;
  //   mutex2.lock();
  //   mutex1.unlock();
  //   mutex2.unlock();

  // Solves deadlock problem
  mutex2.lock();
  mutex1.lock();
  std::cout << "Thread B" << std::endl;
  mutex2.unlock();
  mutex1.unlock();
}

void ExecuteThreads() {
  std::thread t1(ThreadA);
  std::thread t2(ThreadB);

  t1.join();
  t2.join();

  std::cout << "Finished" << std::endl;
}

int main() {
  ExecuteThreads();

  return 0;
}