#include <iostream>

class Point_bad {
  int x;
  int y;

public:
  Point_bad(int xx, int yy) : x{xx}, y{yy} {}
  int get_x() const {
    return x;
  } // const here promises not to modify the object
  void set_x(int xx) { x = xx; }
  int get_y() const {
    return y;
  } // const here promises not to modify the object
  void set_y(int yy) { y = yy; }
  // no behavioral member functions
};

struct Point_Good { // Good: concise
  int x{10};        // public member variable with a default initializer of 0
  int y{20};        // public member variable with a default initializer of 0
};

int main() {
  Point_bad guideline_bad{10, 20};
  Point_Good guideline_good;

  std::cout << guideline_bad.get_x() << guideline_bad.get_y() << "\n";
  std::cout << guideline_good.x << guideline_good.y << "\n";
}