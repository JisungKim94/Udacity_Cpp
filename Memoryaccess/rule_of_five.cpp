#include <iostream>
#include <stdlib.h>

class MyMovableClass {
private:
  int _size;
  int *_data;

public:
  MyMovableClass(size_t size) // constructor
  {
    _size = size;
    _data = new int[_size];
    std::cout << "CREATING instance of MyMovableClass at " << this
              << " allocated with size = " << _size * sizeof(int) << " bytes"
              << std::endl;
  }

  MyMovableClass(const MyMovableClass &source) // 2: copy construct
  {
    _size = source._size;
    _data = new int[_size];
    *_data = *source._data;
    std::cout << "Copying content of instance " << &source << " to instance "
              << this << std::endl;
  }

  MyMovableClass &
  operator=(const MyMovableClass &source) // 3: copy assignment operator
  {
    std::cout << "Assigning content of instance " << &source << " to instance "
              << this << std::endl;

    if (this == &source) {
      return *this;
    }
    delete[] _data;
    _data = new int[source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;
  }

  MyMovableClass(MyMovableClass &&source) // 4 : move constructor
  {
    std::cout << "MOVING (c’tor) instance " << &source << " to instance "
              << this << std::endl;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
  }

  MyMovableClass &
  operator=(MyMovableClass &&source) // 5 : move assignment operator
  {
    std::cout << "MOVING (assign) instance " << &source << " to instance "
              << this << std::endl;
    if (this == &source)
      return *this;

    delete[] _data;

    _data = source._data;
    _size = source._size;

    source._data = nullptr;
    source._size = 0;

    return *this;
  }

  ~MyMovableClass() // 1 : destructor
  {
    std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
    delete[] _data;
  }
};

MyMovableClass createObject(int size) {
  MyMovableClass obj(size);
  return obj;
}

// 걍 function임 class scope안에 있는게 아님
void useObject(MyMovableClass obj) {
  std::cout << "using object " << &obj << std::endl;
}

int main() {
  /* ============================ chapter 1 ============================== */
  MyMovableClass obj1(100);                  // constructor
  obj1 = MyMovableClass(200);                // move assignment operator
  MyMovableClass obj2 = MyMovableClass(300); // move constructor
  /* ============================ chapter 1 ============================== */
  std::cout << std::endl;
  std::cout << "chapter1 is done" << std::endl;
  std::cout << std::endl;

  /* ============================ chapter 2 ============================== */
  MyMovableClass obj3(100); // constructor
  useObject(obj3);

  useObject(MyMovableClass(200));
  // useObject fucntion called with temporary instance
  // of move constructor as its argument;
  // instead of making a copy of it the move constructor is used.
  // which saves us one expensive deep-copy.
  /* ============================ chapter 2 ============================== */
  std::cout << std::endl;
  std::cout << "chapter2 is done" << std::endl;
  std::cout << std::endl;

  /* ============================ chapter 3 ============================== */
  /* The "problem" with our implementation of MyMovableClass is that the call
      useObject(obj1) will trigger the copy constructor as we have seen in one
      of the last examples.But in order to move it, we would have to pretend to
     the compiler that obj1 was an rvalue instead of an lvalue so that we can
     make an efficient move operation instead of an expensive copy. */

  MyMovableClass obj5(100); // constructor
  useObject(std::move(obj5));
  /* ============================ chapter 3 ============================== */
  std::cout << std::endl;
  std::cout << "chapter3 is done" << std::endl;
  std::cout << std::endl;
  return 0;
}
