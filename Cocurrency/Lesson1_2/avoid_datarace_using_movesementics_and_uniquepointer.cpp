#include <future>
#include <iostream>
#include <memory>
#include <thread>
/* std::sttring을 raw -> unique pointer로 바꾸어 쓰면 얘는 메모리 위치를 딱
한곳밖에 못 가리킨다.
std::move를 통해 이동한 uniqueptr는 main thread에서 더이상 사용할 수 없게되고
main에서 부른 v0.getName은 error를 발생시킨다. */

class Vehicle {
public:
  // default constructor
  Vehicle() : _id(0), _name(new std::string("Default Name")) {
    std::cout << "Vehicle #" << _id << " Default constructor called"
              << std::endl;
  }

  // initializing constructor
  Vehicle(int id, std::string name) : _id(id), _name(new std::string(name)) {
    std::cout << "Vehicle #" << _id << " Initializing constructor called"
              << std::endl;
  }

  // move constructor with unique pointer
  Vehicle(Vehicle &&src) : _name(std::move(src._name)) {
    // move id to this and reset id in source
    _id = src.getID();
    src.setID(0);

    // std::cout << Vehicle::getName() << std::endl;
    // line58에선 못부르지만 여기선 부를 수 있음
    // 같은 이유로 src.getName()은 못부름
    std::cout << "Vehicle #" << _id << " move constructor called" << std::endl;
  };

  // setter and getter
  void setID(int id) { _id = id; }
  int getID() { return _id; }
  void setName(std::string name) { *_name = name; }
  std::string getName() { return *_name; }

private:
  int _id;
  std::unique_ptr<std::string> _name;
};

int main() {
  // create instances of class Vehicle
  Vehicle v0;                 // default constructor
  Vehicle v1(1, "Vehicle 1"); // initializing constructor

  // launch a thread that modifies the Vehicle name
  std::future<void> ftr =
      std::async([](Vehicle v) { v.setName("Vehicle 2"); }, std::move(v0));

  ftr.wait();

  // std::cout << v0.getName() << std::endl; // this will now cause an exception

  return 0;
}