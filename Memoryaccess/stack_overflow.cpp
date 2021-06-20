#include <stdio.h>

void stack_overflow(int cnt, int *p_variable_first) {
  cnt = cnt + 1;
  printf("%d: stack bottom : %p, current : %p\n", cnt, &cnt, p_variable_first);
  stack_overflow(cnt, p_variable_first);
}

int main() {
  int variable_first = 0;
  int *p_variable_first = &variable_first;
  int cnt = 0;
  stack_overflow(cnt, p_variable_first);

  /* The left-most number keeps track of the recursion depth while the
   difference between the stack bottom and the current position of the stack
   pointer lets us compute the size of the stack memory which has been used up
   already. Thus last line's current address - stack bottom = max stack memory
   (@ 8Mb at linux and mac)*/
}