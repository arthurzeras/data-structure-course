#include <iostream>

using namespace std;

struct Rectangle {
  int length;
  int width;
};

int main() {
  // Rectangle r = {10, 5};
  // cout << "Using variables: " << r.length << " " << r.width << endl;

  // Rectangle *p = &r;
  // cout << "Using pointers: " << p->length << " " << p->width << endl;

  Rectangle *p;
  // p = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // C Syntax
  p = new Rectangle; // C++ Syntax

  p->width = 5;
  p->length = 10;

  cout << "Using pointers: " << p->length << " " << p->width << endl;

  return 0;
}