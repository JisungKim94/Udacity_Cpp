#include <cassert>
#include <iostream>

// TODO: Declare Vehicle as the base class
class Vehicle {
public:
  int wheels;
};

// TODO: Derive Car from Vehicle
class Car : public Vehicle {
public:
  bool trunk{true};
  int wheels{4};
  int seats;
};

// TODO: Derive Sedan from Car
class Sedan : public Car {
public:
  int seats{4};
};

// TODO: Update main to pass the tests
int main() {
  Vehicle vehicle;
  Sedan sedan;

  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);

  // std::cout << vehicle.wheels; // trash value
}