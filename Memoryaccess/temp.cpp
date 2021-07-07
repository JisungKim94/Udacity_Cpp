#include <stdio.h>
#include <stdlib.h>

/* Problem : In f1, the pointer variable x is a local variable to f1, and f1
 * returns the pointer to that variable. x can disappear after f1() is returned
 * if x exists on the stack. So &x can become invalid. */
// int *f1(void) {
//   int x = 10;
//   return (&x);
// }

/* Problem : In f2, the pointer variable px is assigned a value without
 * allocating its space. */
// int *f2(void) {
//   int *px;
//   *px = 10;
//   return px;
// }

int *f3(void) {
  int *px;
  px = (int *)malloc(sizeof(int));
  *px = 10;
  return px;
}

int main() {
  f2();
  f3();
}