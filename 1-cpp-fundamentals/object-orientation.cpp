#include <iostream>

using namespace std;

class Rectangle {
private:
  int length;
  int width;

public:
  Rectangle(int l, int w) {
    length = l;
    width = w;
  }

  int area() { return length * width; }

  int perimeter() { return 2 * (length + width); }

  int getLength() { return length; }

  void setLength(int l) { length = l; }

  int getWidth() { return width; }

  void setWidth(int w) { width = w; }

  ~Rectangle() {}
};

int main() {
  Rectangle r(10, 5);
  cout << r.area() << endl;
  cout << r.perimeter() << endl;
}