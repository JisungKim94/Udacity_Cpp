#include <iostream>

void AddTwo(int val) { val += 2; }

int main() {
  int val = 0;
  AddTwo(val);
  val += 2;

  std::cout << "val = " << val << std::endl;
  // copy를 해서 사용하지만 parameter val 값은 안바뀜
  // Consider the example on the right in the pass_by_value.cpp file. In main,
  // the integer val is initialized with 0. When passing it to the function
  // AddTwo, a local copy of val is created, which only exists within the scope
  // of AddTwo, so the add-operation has no effect on val on the caller side. So
  // when main returns, val has a value of 2 instead of 4.
  return 0;
}