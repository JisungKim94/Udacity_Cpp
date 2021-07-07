#include <iostream>

using namespace std;

// This class for managing a template-based heap ressource implements move
// semantics
// template <typename T> 와 template <class T> 는 정확히 같은 의미를 같지만
// 되도록이면 typename 키워드를 사용하기를 권장합니다.
template <typename T> class MyClass {
  T *data = nullptr;

private:
  // copy constructor
  MyClass(const MyClass &);

  // copy assignment operator
  MyClass &operator=(const MyClass &);

public:
  MyClass() {}

  // move constructor
  MyClass(MyClass &&other) {
    data = other.data;
    other.data = nullptr;
  }

  // move assignment operator
  MyClass &operator=(MyClass &&other) {
    if (this != &other) {
      if (data) {
        delete data;
      }
      data = other.data;
      other.data = nullptr;
    }

    return *this;
  }

  ~MyClass() {
    if (data) {
      delete data;
    }
  }
};

int main() {
  /* EXERCISE 3-1: create an instance h1 of class MyClass with data of type
   * 'double' using the regular constructor */
  // TODO: SOLUTION 3-1
  MyClass<double> h1;

  // /* EXERCISE 3-2: create an instance h2 of class MyClass using the move
  // constructor (moving from h1) */
  // TODO: SOLUTION 3-2
  MyClass<double> h2 = move(h1); // h1 : lvalue thus, have to use std::move

  /* EXERCISE 3-3: disable copying for class MyClass */
  // TODO: SOLUTION 3-3
  // set visibility of MyClass(const MyClass &) and of MyClass &operator=(const
  // MyClass &) to private
}