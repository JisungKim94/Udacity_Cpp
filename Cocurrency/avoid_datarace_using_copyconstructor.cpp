#include <future>
#include <iostream>
#include <thread>

/* 이렇게 코드를 짜면 (copyconstructor) async내에 v0를 카피해서 사용하기 때문에
바깥에서 바꾸면 v0가 제대로 바뀌어서 async wait가 불리기 전에 (=끝나기 전에)
v0.setName("Vehicle 3"); 를해도 v0가 잘 바뀐걸 볼 수 있다.
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

  // copy constructor
  Vehicle(Vehicle const &src) {
    // QUIZ: Student code STARTS here
    if (src._name != nullptr) {
      _id = src._id;
      _name = new std::string;
      *_name = *src._name;
    }
    // QUIZ: Student code ENDS here
    std::cout << "Vehicle #" << _id << " copy constructor called" << std::endl;
  };

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