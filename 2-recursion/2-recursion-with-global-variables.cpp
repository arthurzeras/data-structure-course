#include <iostream>

using namespace std;
int y = 0;

int function1(int x) {
  // static int y = 0;

  if (x > 0) {
    y++;
    return function1(x - 1) + y;
  }

  return 0;
}

int main() {
  cout << function1(5) << endl;

  return 0;
}