#include <iostream>
#include <memory>
#include <string>

class MyClass {
private:
  std::string _text;

public:
  MyClass() {}
  MyClass(std::string text) { _text = text; }
  ~MyClass() { std::cout << _text << " destroyed" << std::endl; }
  void setText(std::string text) { _text = text; }
};

int main() {
  // create unique pointer to proprietary class
  std::unique_ptr<MyClass> myClass1(new MyClass());
  std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));

  // call member function using ->
  myClass1->setText("String 1");

  // use the dereference operator *
  *myClass1 = *myClass2;

  // use the .get() function to retrieve a raw pointer to the object
  std::cout << "Objects have stack addresses " << myClass1.get() << " and "
            << myClass2.get() << std::endl;

  /* both pointers have different addresses(different resource) on the stack,
even after copying the contents from myClass2 to myClass1 왜냐하면 unique
pointer is which exclusively owns a dynamically allocated resource on the heap.
동일한 리소스에 대한 두 번째 고유 포인터가 없어야합니다.*/

  return 0;
}