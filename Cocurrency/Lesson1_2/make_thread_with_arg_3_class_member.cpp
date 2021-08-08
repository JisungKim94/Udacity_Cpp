#include <iostream>
#include <thread>

class Vehicle {
public:
  Vehicle() : _id(0) {}
  void addID(int id) { _id = id; }
  void printID() { std::cout << "Vehicle ID=" << _id << std::endl; }

private:
  int _id;
};

int main() {
  // create thread
  Vehicle v1;
  // call member function on object v1 copy
  std::thread t1 = std::thread(&Vehicle::addID, v1, 1);

  //   Vehicle v2;
  // call member function on object v2 directly
  // std::thread t2 = std::thread(&Vehicle::addID, &v2, 2); // without ptr

  /* ========================== Use Shared_Ptr ========================== */
  // 2번째 방식은 v2가 t2보다 오래 살아있어야 함 안그러면 invalidated memory
  // address에 접근하니께... 좋은 대안으로 shared_ptr가 있다.
  // 얘가 사용될 때 (t2 동안)존재하고 t2가 끝나면 알아서 v2가 deallocated된다.
  std::shared_ptr<Vehicle> v2(new Vehicle);
  std::cout << "counter make shared_ptr v2 =" << v2.use_count() << std::endl;
  std::thread t2 = std::thread(&Vehicle::addID, v2, 1);

  // v2 counter
  std::cout << "v2 counter before t2 lifetime =" << v2.use_count() << std::endl;
  /* ========================== Use Shared_Ptr ========================== */

  // wait for thread to finish
  t1.join();
  t2.join();
  std::cout << "v2 counter after t2 lifetime =" << v2.use_count() << std::endl;

  // print Vehicle id
  v1.printID();
  v2->printID();

  return 0;
}