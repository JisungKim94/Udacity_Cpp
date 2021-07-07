#include <stdio.h>

void CallByValue(int i) {
  int j = 1;
  printf("call-by-value: %p\n", &j);
}

void CallByPointer(int *i) {
  int j = 1;
  printf("call-by-pointer: %p\n", &j);
}

void CallByReference(int &i) {
  int j = 1;
  printf("call-by-reference: %p\n", &j);
}

int main() {
  int i = 0;
  printf("stack bottom: %p\n", &i);

  CallByValue(i);

  CallByPointer(&i);

  CallByReference(i);

  return 0;
}
/* After creating a local variable i in main to give us the address of the stack
 * bottom, we are passing i by-value to our first function. Inside CallByValue,
 * the memory address of a local variable j is printed to the console, which
 * serves as a marker for the stack pointer. With the second function call in
 * main, we are passing a reference to i to CallByPointer. Lastly, the function
 * CallByReference is called in main, which again takes the integer i as an
 * argument. However, from looking at main alone, we can not tell wether i will
 * be passed by value or by reference.
 *
 * Depending on your system, the compiler you use and the compiler optimization
 * techniques, you man not always see this result. In some cases
 *
 * But if has not any optimization, CallByValue : 32byte(hex 20),
 * CallByRef/CallByPointer : 36btye (hex 24) requires memory.
 *
 *
/* In this section, we have argued at length that passing a parameter by
 * reference avoids a costly copy and should - in many situations - be preferred
 * over passing a parameter by value. Yet, in the experiment above, we have
 * witnessed the exact opposite.

 * Can you explain why?
 * Let us take a look at the size of the various parameter types using the
 * sizeof
 * command:
 * printf("size of int: %lu\n", sizeof(int));
 * printf("size of *int: %lu\n", sizeof(int *));
 *
 * The output here is
 * size of int: 4
 * size of *int: 8
 *
 * Obviously, the size of the pointer variable is larger than the actual data
 * type.
 * As my machine has a 64 bit architecture, an address requires 8 byte.
 *
 * As an experiment, you could use the -m32 compiler flag to build a 32 bit
 * version
 * of the program.
 *
 * This yields the following output:
 * size of int: 4
 * size of *int: 4
 *
 * In order to benefit from call-by-reference, the size of the data type passed
 * to
 * the function has to surpass the size of the pointer on the respective
 * architecture (i.e. 32 bit or 64 bit). */