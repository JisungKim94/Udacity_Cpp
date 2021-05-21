#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<int> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n);
    }
    return row;
}

// TODO: Change the return type of ReadBoardFile.
vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile (path);
  // TODO: Declare an empty board variable here with
  vector<vector<int>> board;
  vector<int> row;
  
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      // TODO: Replace the "cout" code with a call to ParseLine for each line and push the results of ParseLine to the back of the board.
      row = ParseLine(line);
      board.push_back(row);
      // board에 row 추가하는데 왜 column이 알아서 한 줄 씩 바뀔까?
      // -> board vector는 2D -> vector_column,vector_row로 이루어져 있고 push로 하나 채웠으니까 다음걸로 넘어가는게 당연한거
    }
  }
  // TODO: Return the board variable.
  return board;
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  vector<vector<int>> board;
  // TODO: Store the output of ReadBoardFile in the "board" variable.
  board = ReadBoardFile("files/1.txt");
  // TODO: Uncomment PrintBoard below to print "board".
  PrintBoard(board);
}