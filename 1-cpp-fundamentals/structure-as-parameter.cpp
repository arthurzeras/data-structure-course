#include <iostream>

using namespace std;

struct Rectangle {
  int length;
  int width;
};

struct Example {
  int arr[5];
  int length;
};

struct Rectangle *createRectangle(int length, int width) {
  // struct Rectangle *r = new Rectangle;
  struct Rectangle *r = (struct Rectangle *)malloc(sizeof(struct Rectangle));
  r->length = 10;
  r->width = 5;
  return r;
}

int getAreaByValue(struct Rectangle r) { return r.length * r.width; }
int getAreaByAddress(struct Rectangle *r) { return r->length * r->width; }

/**
 * Arrays cannot be passed by value but inside a struct they can be.
 */
void showStructWithArray(struct Example ex) {
  ex.arr[0] = 100;
  for (int i = 0; i < ex.length; i++) {
    cout << ex.arr[i] << " ";
  }
  cout << endl;
}

int main() {
  Rectangle rec = {10, 5};
  Example ex = {{1, 2, 3, 4, 5}, 5};

  // Rectangle *rec = createRectangle(5, 10);

  cout << "Area using parameter by value: " << getAreaByValue(rec) << endl;
  cout << "Area using parameter by address: " << getAreaByAddress(&rec) << endl;

  // showStructWithArray(ex);
  return 0;
}