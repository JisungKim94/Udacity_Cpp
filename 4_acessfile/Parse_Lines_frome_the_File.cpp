#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;

// TODO: Add the ParseLine function here.
vector<int> ParseLine(string line){
  istringstream mystream(line);
  
  int n;
  char c;
  vector<int> a;	// vector 여기 놔두면 while다 돌 때까지 a유지되므로 a[0] -> a[1] -> a[2] .... 으로 pushback 된다.
  
  while (mystream>>n>>c){
//     vector<int> a;	//	vector 여기 놔두면 while 안에 있는 local이라 pushback을 하면 a[0]에 n이 저장되고 없어지고 반복
    a.push_back(n);
//     cout<<"for debug"<<"\n";
    // vector 전체를 출력하는 방법은 없는듯 elements 하나 씩 선택 해 줘야 함
//     cout<<a[0]<<"\n";
  }
  return a;
}

char ReadBoardFile(string path) {
  ifstream myfile (path);
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
//       cout << line << "\n";
    }
  }
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

#include "test_for_Parse_Lines_frome_the_File.cpp" // For testing.

int main() {
  ReadBoardFile("files/1.txt");
  TestParseLine(); // For testing.
  // Leave commented out.
  // PrintBoard(board);
}