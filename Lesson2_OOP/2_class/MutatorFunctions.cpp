#include <cstring>
#include <iostream>
#include <string>

class Car {
  // TODO: Declare private attributes
private:
  int horsepower_{0};
  int weight_{0};
  char *brand_;

  // TODO: Declare getter and setter for brand
public:
  void set_horsepower(int horesepower);
  void set_weight(int weight);
  void set_brand(std::string brand);
  int get_horsepower();
  int get_weight();
  std::string get_brand();
};

// Define setters
void Car::set_horsepower(int horsepower) { horsepower_ = horsepower; }
void Car::set_weight(int weight) { weight_ = weight; }
void Car::set_brand(std::string brand) {
  // Initialization of char array
  Car::brand_ = new char[brand.length() + 1];
  // copying every character from string to char array;
  strcpy(Car::brand_, brand.c_str());
}
// Define getters
int Car::get_horsepower() { return horsepower_; }
int Car::get_weight() { return weight_; }
std::string Car::get_brand() {
  std::string result = "Brand name: ";
  // Specifying string for output of brand name
  result += Car::brand_;
  return result;
};

// Test in main()
int main() {
  Car car;
  car.set_brand("Peugeot");
  std::cout << car.get_brand() << "\n";
}