#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream my_file;  // std::ifstream class 를 맨날 치기 귀찮으니까 my_file로 쓰겠다.
    my_file.open("files/1.txt");
    if (my_file) {
        std::cout << "The file stream has been created!" << "\n";
        
        std::string line;   // std::string class를 맨날 치기 귀찮으니까 line으로 쓰겠다.
        while (getline(my_file, line)) {
            std::cout << line << "\n";
        }
    }
}