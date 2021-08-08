#include <future>
#include <iostream>
#include <thread>

/* Data race란, a data race requires simultaneous access from two threads */
/* 이렇게 코드를 짜면 datarace가 발생한다. async 끝나기 전에
v0.setName("Vehicle 3"); 한게 안먹히고 여전히 Vehicle 2로 남아있는걸 볼
수 있담.
*/
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

  // setter and getter
  void setID(int id) { _id = id; }
  int getID() { return _id; }
  void setName(std::string name) { *_name = name; }
  std::string getName() { return *_name; }

private:
  int _id;
  std::string *_name;
};

int main() {
  // create instances of class Vehicle
  Vehicle v0;                 // default constructor
  Vehicle v1(1, "Vehicle 1"); // initializing constructor

  // launch a thread that modifies the Vehicle name
  std::future<void> ftr = std::async(
      [](Vehicle v) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(500)); // simulate work
        v.setName("Vehicle 2");
      },
      v0);

  v0.setName("Vehicle 3");

  ftr.wait();
  std::cout << v0.getName() << std::endl;

  return 0;
}