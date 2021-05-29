#include <iostream>
#include "class_temp.h"
using std::cout;
using std::endl;

void student::showinfo(){
    cout << "name: " << name << ", age: " << age << ", hobby: " << hobby << endl;
}

void student::study(){
    cout<<"studing.."<<endl;
}

void student::sleep(){
    cout<<"sleeping.."<<endl;
}