#include <iostream>

using namespace std;

/* nCr combination formula */

int factorial(int n) {
  int r = 1;

  for (int i = 1; i <= n; i++) {
    r = r * i;
  }

  return r;
}

int c(int n, int r) {
  int t1 = factorial(n);
  int t2 = factorial(r);
  int t3 = factorial(n - r);
  return t1 / (t2 * t3);
}

int c2(int n, int r) {
  if (n == r or r <= 0) {
    return 1;
  }

  return c2(n - 1, r - 1) + c2(n - 1, r);
}

int main() {
  cout << c2(10, 1) << endl;

  return 0;
}