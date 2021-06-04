// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
  int wheels = 0;
  string color = "blue";

  void Print() const {
    std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
  }
};

class Car : public Vehicle {
public:
  bool sunroof = false;
};

class Bicycle : protected Vehicle {
public:
  bool kickstand = true;
  void Wheels(int w) { wheels = w; }
  void Print() const {
    std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
  }
};

class Scooter : private Vehicle {
public:
  bool electric = false;
  void Wheels(int w) { wheels = w; }
  void Print() const {
    std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
  }
};

int main() {
  Car car;
  car.wheels = 4;
  car.color = "red";

  Bicycle bicycle;
  //   bicycle.color = "green"; // Can't access protected
  bicycle.Wheels(2); // child class 내부에서 바꾸는건 가능

  Scooter scooter;
  //   scooter.color = "yellow"; // Can't access private
  scooter.Wheels(1); // child class 내부에서 바꾸는건 가능

  car.Print();
  std::cout << "\n";
  bicycle.Print(); // child class 내부에서 바꾸는건 가능 (Wheels는 되는데
                   // color는 안됨)
  std::cout << "\n";
  scooter.Print(); // child class 내부에서 바꾸는건 가능 (Wheels는 되는데
                   // color는 안됨)
  std::cout << "\n";
};