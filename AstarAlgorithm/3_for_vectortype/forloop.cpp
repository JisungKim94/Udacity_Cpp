#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  auto i = 1;

  // Post-increment assigns i to c and then increments i.
  auto c = i++;

  cout << "Post-increment example:"
       << "\n";
  cout << "The value of c is: " << c << "\n";
  cout << "The value of i is: " << i << "\n";
  cout << "\n";

  // Reset i to 1.
  i = 1;

  // Pre-increment increments i, then assigns to c.
  c = ++i;

  cout << "Pre-increment example:"
       << "\n";
  cout << "The value of c is: " << c << "\n";
  cout << "The value of i is: " << i << "\n";
  cout << "\n";

  // Decrement i;
  i--;
  cout << "Decrement example:"
       << "\n";
  cout << "The value of i is: " << i << "\n";

  // Add your code here.
  vector<vector<int>> b{{1, 2}, {3, 4}, {5, 6}};

  // Write your double loop here.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cout << b[i][j] << '\n';
    }
  }

  // Write your double loop here.
  // base ranged for loop (range base for loop)
  // https://blockdmask.tistory.com/319
  for (auto v : b) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << "\n";
  }

  // 좀 더 쉬운 예시
  // 출처: https://boycoding.tistory.com/210
  int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  for (int number : fibonacci)
    std::cout << number << ' ' << std::endl;
}