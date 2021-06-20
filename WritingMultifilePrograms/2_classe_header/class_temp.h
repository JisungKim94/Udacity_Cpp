#ifndef CLASS_TEMP_H
#define CLASS_TEMP_H

#include <string>
using std::string;

class student {
    private:
        string name;
        int age;
        string hobby;

    public:
        void showinfo();
        void study();
        void sleep();

        //Construct
        student(string n, int a, string h): name(n), age(a), hobby(h) {}
};

#endif