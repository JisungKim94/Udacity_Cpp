/* Recall that a data race requires simultaneous access from two threads.If we
   can guarantee that only a single thread at a time can access a particular
   memory location, data races would not occur In order for this to work, we
   would need to establish a communication protocol. It is important to note
   that a mutex is not the solution to the data race problem per se but merely
   an enabler for a thread-safe communication protocol that has to be
   implemented and adhered to by the programmer.*/

// Mutex 적용 전

#include <algorithm>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

class Vehicle {
public:
  Vehicle(int id) : _id(id) {}

private:
  int _id;
};

class WaitingVehicles {
public:
  WaitingVehicles() : _tmpVehicles(0) {}

  // getters / setters
  void printSize() { std::cout << "#vehicles = " << _tmpVehicles << std::endl; }

  // typical behaviour methods
  void pushBack(Vehicle &&v) {
    //_vehicles.push_back(std::move(v)); // data race would cause an exception
    int oldNum = _tmpVehicles;
    std::this_thread::sleep_for(std::chrono::microseconds(
        1)); // wait deliberately to expose the data race
    _tmpVehicles = oldNum + 1;
  }

private:
  std::vector<Vehicle>
      _vehicles; // list of all vehicles waiting to enter this intersection
  int _tmpVehicles;
};

int main() {
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
  std::vector<std::future<void>> futures;
  // case 1. if Running the program synchronously with launch option
  // std::launch::deferred, will output queue size is 1000
  // case 2. if Running the program synchronously with launch option
  // std::launch::async, will output queue size is randomly

  /* at case 2 it seems that not all the vehicles could be added to the
     queue.But why is that ? Note that in the thread function "pushBack" there
     is a call to sleep_for, which pauses the thread execution for a short
     time.This is the position where the data race occurs : */

  // 더 자세한 내용은
  // https://classroom.udacity.com/nanodegrees/nd213/parts/7f8f6354-1461-493e-8542-8dd742bd205b/modules/f9303387-4b04-457b-ad28-a8c0e054e90b/lessons/141f4f78-90f8-48f5-949e-233818890541/concepts/28ccaed0-1058-4a50-9311-f2a66b101c97
  // Workspace 2번째 page 참고

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
