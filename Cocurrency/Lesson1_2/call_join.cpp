#include <iostream>
#include <thread>

/* 메인 쓰레드가 다른 쓰레드보다 먼저 끝나면 리소스에 접근 할 방법이 없으므로
안에서 돌던 애들이 끝이 안남. 이걸 방지하기 위해 사용하는게 join() */

void threadFunction() {
  std::this_thread::sleep_for(
      std::chrono::milliseconds(100)); // simulate work thread t
  std::cout << "Finished work in thread\n";
}

int main() {
  // create thread
  std::thread t(threadFunction);
  // t.join();
  // do something in main()
  std::this_thread::sleep_for(
      std::chrono::milliseconds(50)); // simulate work main thread
  std::cout << "Finished work in main\n";

  // main thread wait for thread t to finish
  t.join();
  // without join() : terminate called without an active exception
  // Aborted(coredumped)

  // 만약 t.join(); 을 // do something in main() 위로 올리면
  // t thread가 종료된 이후 main이 종료될거임 t.join은 t 끝날 때 까지
  // 대기시키니까

  return 0;
}