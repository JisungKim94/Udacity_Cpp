#include <assert.h>

// TODO: Define Point class
class Point {
  // TODO: Define public constructor
public:
  Point(int x_ = 0, int y_ = 0)
      : x(x_), y(y_) {} // 일케하면 Point() 일땐 0,0 이고 arg 있을땐 그거 사용
  // TODO: Define + operator overload
  Point operator+(Point &p) {
    Point sum;
    sum.x = x + p.x;
    sum.y = y + p.y;
    return sum;
  }

  // TODO: Declare attributes x and y
  int x;
  int y;
};

// Test in main()
int main() {

  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}