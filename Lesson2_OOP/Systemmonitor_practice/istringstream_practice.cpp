#include <iostream>
#include <sstream>

// build 할 때 최신 g++ 아니면 header 추가 안되넹?

int main() {
  std::istringstream iss("test 123 123hah ahha 567");
  std::string str, str1, str2;
  int inta;
  int intb;

  std::cout << iss.str() << std::endl;
  iss >> str >> str1 >> str2 >> inta >> intb;
  std::cout << "str  : " << str << std::endl;
  std::cout << "str1 : " << str1 << std::endl;
  std::cout << "str2 : " << str2 << std::endl;
  std::cout << "inta : " << inta << std::endl; // int 아님
  std::cout << "intb : " << inta << std::endl; // int 아님
}