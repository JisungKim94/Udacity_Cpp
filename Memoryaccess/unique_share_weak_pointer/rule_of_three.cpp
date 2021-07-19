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

int main() {
  // copying이랑 moving이 둘 다 있는데, cout에 copying 없으면 moving이라고 볼 수
  // 있음 여기선 컴파일러가 해주는데, rule of five에선 move constructor 구현할거
  /* ============================ chapter 1 ============================== */
  //   MyMovableClass obj1(10);   // regular constructor
  //   MyMovableClass obj2(obj1); // copy constructor
  //   obj2 = obj1;               // copy assignment operator
  /*   call to copy constructor, (alternate syntax) */
  //   MyMovableClass obj3 = obj1;
  /* Here, we are instantiating obj3 in the same statement; compare to
  "MyMovableClass obj2(obj1); AND obj2 = obj1;" hence the copy assignment
  operator would not be called. */
  /* ============================ chapter 1 ============================== */

  /* ============================ chapter 2 ============================== */
  //   MyMovableClass obj4 = createObject(10);
  //   obj4 = createObject(10);
  /* createObject(10) returns a temporary copy of the object as an rvalue, which
  is passed to the copy constructor. */

  /*
   * You can try executing the statement below as well
   */
  MyMovableClass obj4(createObject(10));
  /* ============================ chapter 2 ============================== */

  return 0;
}
