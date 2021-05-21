#include <iostream>
using std::cout;

/* 
Passing Values
In the code "passing_value.cpp", a is passed by value to the function, so the variable a is not affected by what happens inside the function.

Passing References
But what if we wanted to change the value of a itself? For example, it might be that the variable you are passing into a function maintains some state in the program, and you want to write the function to update that state.

It turns out, it is possible to modify a from within the function. To do this, you must pass a reference to the variable a, instead of the value of a. In C++, a reference is just an alternative name for the same variable.

To pass by reference, you simply need to add an ampersand & before the variable in the function declaration. Try the code below to see how this works: */

int MultiplyByTwo(int &i) {
    i = 2*i;
    return i;
}

int main() {
    int a = 5;
    cout << "The int a equals: " << a << "\n";
    int b = MultiplyByTwo(a);
    cout << "The int b equals: " << b << "\n";
    cout << "The int a now equals: " << a << "\n";
}