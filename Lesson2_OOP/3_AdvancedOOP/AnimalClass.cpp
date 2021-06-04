#include <iostream>
#include <string>

using std::string;

// Define base class Animal
class Animal {
private:
public:
  string color;
  string name;
  int age;
};
// Declare derived class Snake
class Snake : public Animal {
private:
public:
  void MakeSound() {
    std::cout << "Sss"
              << "\n";
  }
};
// Declare derived class Cat
class Cat : public Animal {
private:
public:
  int height;
  void MakeSound() {
    std::cout << "Meo"
              << "\n";
  }
};
// Test in main()
int main() {
  Snake snake;
  Cat cat;

  cat.age = 1;
  cat.color = "black";
  cat.name = "nabi";
  cat.height = 50;
  snake.age = 2;
  snake.color = "white";
  snake.name = "baam";

  snake.MakeSound();
  std::cout << cat.age << " " << cat.name << "\n";
  cat.MakeSound();
}