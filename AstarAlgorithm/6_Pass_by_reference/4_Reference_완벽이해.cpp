#include <iostream>
using std::cout;

/* This is extremely important to remember. For the & symbol, if it appears on the left side of an equation (e.g. when declaring a variable), it means that the variable is declared as a reference. If the & appears on the right side of an equation, or before a previously defined variable, it is used to return a memory address
j는 선언할 때 int &j 였으므로 Reference고 i는 그냥 int 선언이니까 &i 불러오면 address가 나옴*/

int main() 
{
    int i = 1;
    
    // Declare a reference to i.
    int& j = i;
    cout << "The value of j is: " << j << "\n";
    cout << "The address of i is: " << &i << "\n";
    
    // Change the value of i.
    i = 5;
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is now: " << j << "\n";
    
    // Change the value of the reference.
    // Since reference is just another name for the variable,
    // th
    j = 7;
    cout << "The value of j is now: " << j << "\n";
    cout << "The value of i is changed to: " << i << "\n";
}

