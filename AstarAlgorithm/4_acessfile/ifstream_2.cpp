#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::string;
using std::vector;
using std::ifstream;

void ReadBoardFile(string path) {
    ifstream myfile (path);
    if (myfile) {
        string line;
        while (getline(myfile, line)) {
            cout << line << "\n";
        }
    }
}

int main(){
    ReadBoardFile("files/1.txt");
}