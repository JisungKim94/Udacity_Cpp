#include <iostream>

void AddFour(int &val) { val += 4; }

void AddSix(int *val) { *val += 6; }

int main() {
  int val = 0;
  AddFour(val);
  AddSix(&val);

  std::cout << "val = " << val << std::endl;

  return 0;
}

// If passing by value needs to be avoided, both pointers and references are a
// way to achieve this. The following selection of properties contrasts the two
// methods so it will be easier to decide which to use from the perspective of
// the use-case at hand:

// Pointers can be declared without initialization. This means we can pass an
// uninitialized pointer to a function who then internally performs the
// initialization for us.

// Pointers can be reassigned to another memory block on the heap.

// References are usually easier to use (depending on the expertise level of the
// programmer). Sometimes however, if a third-party function is used without
// properly looking at the parameter definition, it might go unnoticed that a
// value has been modified.