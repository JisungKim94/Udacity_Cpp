#include <iostream>

void AddThree(int *val) { *val += 2; }

int main() {
  int val = 0;
  AddThree(&val);
  val += 2;

  std::cout << "val = " << val << std::endl;
  // copy는 있지만 parameter val 값은 직접 바뀜
  // In this case, when passing the parameter to the function AddThree, we are
  // creating a local copy as well but note that we are now passing a pointer
  // variable. This means that a copy of the memory address of val is created,
  // which we can then use to directly modify its content by using the
  // dereference operator *.
  return 0;
}