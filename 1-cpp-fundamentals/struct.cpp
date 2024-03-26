#include <iostream>

using namespace std;

struct Rectangle {
  int length;
  int breadth;
};

struct Card {
  int number;
  int shape;
  int color;
};

struct Deck {
  Card cards[52];
};

int main() {
  struct Rectangle r = {10, 5};
  cout << sizeof(r) << endl;
  return 0;
}