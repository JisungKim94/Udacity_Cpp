#include <iostream>

void AddFour(int &val) { val += 2; }

int main() {
  int val = 0;
  AddFour(val);
  val += 2;

  std::cout << "val = " << val << std::endl;
  // copy를 안해서 parameter val 값이 직접 바뀜, 빠름, 메모리도 덜 씀 데이터에
  // 어떤 일이 일어나고 있는지 몰라서 좀 위험함
  // the function receives a reference to
  // the parameter, rather than a copy of its value. As with the example of
  // AddThree above, the function can now modify the argument such that the
  // changes also happen on the caller side. In addition to the possibility
  // to directly exchange information between function and caller, passing
  // variables by reference is also faster as no information needs to be
  // copied, as well as more memory-efficient.
  return 0;
}
