/* Recall that a data race requires simultaneous access from two threads.If we
   can guarantee that only a single thread at a time can access a particular
   memory location, data races would not occur In order for this to work, we
   would need to establish a communication protocol. It is important to note
   that a mutex is not the solution to the data race problem per se but merely
   an enabler for a thread-safe communication protocol that has to be
   implemented and adhered to by the programmer.*/

// Mutex 적용 후
// 더 좋은 방법은 Using_Locks_to_Avoid_Deadlocks.cpp에 있음

#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Vehicle {
public:
  Vehicle(int id) : _id(id) {}
  int getID() { return _id; }

private:
  int _id;
};

class WaitingVehicles {
public:
  WaitingVehicles() {}

  // getters / setters
  void printSize() {
    _mutex.lock();
    std::cout << "#vehicles = " << _vehicles.size() << std::endl;
    _mutex.unlock();
  }

  // typical behaviour methods
  void pushBack(Vehicle &&v) {
    // attempt to 3 times until succeed try lock
    for (size_t i = 0; i < 3; ++i) {
      // if문 조건 안에 들어있어도 함수는 실행되네..
      // case 1. using try_lock
      if (_mutex.try_lock()) {
        // case 2. using try_lock_for (only can use timed_mutex)
        //   if (_mutex.try_lock_for(std::chrono::milliseconds(50))) {
        _vehicles.emplace_back(std::move(v));
        // std::this_thread::sleep_for(std::chrono::milliseconds(1));
        _mutex.unlock();
        break;
      } else {
        std::cout << "Error! Vehicle #" << v.getID()
                  << " could not be added to the vector "
                  << "attempt = " << i + 1 << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  }

private:
  std::vector<Vehicle>
      _vehicles; // list of all vehicles waiting to enter this intersection
  std::timed_mutex _mutex;
};

int main() {
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
  std::vector<std::future<void>> futures;
  for (int i = 0; i < 1000; ++i) {
    Vehicle v(i);
    futures.emplace_back(std::async(
        std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
  }

  std::for_each(futures.begin(), futures.end(),
                [](std::future<void> &ftr) { ftr.wait(); });

  queue->printSize();

  return 0;
}
