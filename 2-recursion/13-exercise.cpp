#include <iostream>

using namespace std;

int f(int &x, int c) {
  c = c - 1;
  printf("c: %d\n", c);
  if (c == 0)
    return 1;
  x = x + 1;
  printf("x: %d\n", x);
  int r = f(x, c) * x;
  printf("r: %d x: %d c: %d\n", r, x, c);
  return r;
}

int main() {
  int p = 5;

  cout << f(p, p) << endl;

  return 0;
}