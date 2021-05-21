#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> brothers{"Kim", "Kimt", "KimTa = 1;"};
    float a2 = 1;
    for (std::string const& brother : brothers) {
        std::cout << "hello " << brother << "!\n";
    }   
    
}