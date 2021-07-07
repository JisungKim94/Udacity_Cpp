#include <iostream>
#include <memory>

/* reasons why weak pointer need ? and what is circular reference */

class MyClass {
public:
  std::shared_ptr<MyClass> _member;
  ~MyClass() { std::cout << "Destructor of MyClass called" << std::endl; }
};

int main() {
  std::shared_ptr<MyClass> myClass1(new MyClass);
  std::shared_ptr<MyClass> myClass2(new MyClass);

  // weak pointer가 필요한 이유
  // 아래에 있는 순환 참조를 comment in 하면 main이 끝나도 소멸이 안댐

  //   myClass1->_member = myClass2;
  //   myClass2->_member = myClass1;

  /* myClass1이 main의 끝에서 범위를 벗어나면 myClass2의 공유 포인터 _member에
     의해 발생하는 스마트 포인터에 여전히 참조 수가 1이므로 해당 소멸자는
     메모리를 정리할 수 없습니다 .myClass1에 여전히 공유 포인터가 있기 때문에
     제대로 삭제할 수없는 myClass2도 마찬가지입니다. */

  return 0;
}