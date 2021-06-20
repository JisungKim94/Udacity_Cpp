#include <stdio.h>
#include <string>

void MyFunc() {
  int k = 3;
  printf("3: %p \n", &k);
}

int main() {

  int i = 1;
  printf("1: %p \n", &i);

  int j = 2;
  printf("2: %p \n", &j);

  MyFunc();

  int l = 4;
  printf("4: %p \n\n", &l);

  std::string txt =
      "Between 1 and 2, the stack address is reduced by 4 bytes, which corresponds\
  to the allocation of memory for the int j. Between 2 and 3, the address pointer is moved by 0x28. We can easily see that\
  calling a function causes a significant amount of memory to be allocated. In\
  addition to the local variable of MyFunc, the compiler needs to store additional\
  data such as the return address.";
  printf("%s", txt.c_str());
  return 0;
}