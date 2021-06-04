// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>
using std::abs;
// TODO: Define pi
#define PI 3.141592

// TODO: Define the abstract class Shape
class Shape {
public:
  // TODO: Define public virtual functions Area() and Perimeter()
  // TODO: Append the declarations with = 0 to specify pure virtual functions
  virtual float Area() const = 0;
  virtual float Perimeter() const = 0;
};

// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle : public Shape {
private:
  // TODO: Declare private attributes width and height
  float width_;
  float height_;

public:
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()

  Rectangle(float width, float height) : width_(width), height_(height){};
  float Area() const override {
    return width_ * height_;
  } // override란 부모에서 정의된 함수를 자식이 나는 이렇게 쓰기 싫어 하고
    // 바꾸는거 (override 키워드는 안써도 상관은 없지만, 코드가 재정의를 하는지
    // override를 하는지 컴파일러에게 알리기 때문에 상속은 안받거나 하면
    // 컴파일러가 에러를 띄워서  명확해진다.)
  float Perimeter() const override {
    return (width_ + height_) * 2;
  } // override란 부모에서 정의된 함수를 자식이 나는 이렇게 쓰기 싫어 하고
    // 바꾸는거 (override 키워드는 안써도 상관은 없지만, 코드가 재정의를 하는지
    // override를 하는지 컴파일러에게 알리기 때문에 상속은 안받거나 하면
    // 컴파일러가 에러를 띄워서  명확해진다.)
};

// TODO: Define Circle to inherit from Shape
class Circle : public Shape {
private:
  // TODO: Declare private member variable radius
  float radius_;

public:
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()

  Circle(float radius) : radius_(radius) {}
  float Area() const override {
    return radius_ * radius_ * PI;
  } // override란 부모에서 정의된 함수를 자식이 나는 이렇게 쓰기 싫어 하고
    // 바꾸는거 (override 키워드는 안써도 상관은 없지만, 코드가 재정의를 하는지
    // override를 하는지 컴파일러에게 알리기 때문에 상속은 안받거나 하면
    // 컴파일러가 에러를 띄워서  명확해진다.)
  float Perimeter() const override {
    return 2 * PI * radius_;
  } // override란 부모에서 정의된 함수를 자식이 나는 이렇게 쓰기 싫어 하고
    // 바꾸는거 (override 키워드는 안써도 상관은 없지만, 코드가 재정의를 하는지
    // override를 하는지 컴파일러에게 알리기 때문에 상속은 안받거나 하면
    // 컴파일러가 에러를 띄워서  명확해진다.)
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}