#include <iostream>
#include <vector>
using std::cout;
using std::vector;

// 
// vector type 이런식으로 해야댐
// 

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0}};
  PrintBoard(board);
  cout<<"\n";

  // other vector experession
  vector<int> vector0(4,0);
  vector<vector<int>> vector1(3,vector0);
  PrintBoard(vector1);
}