#include <iostream>

using namespace std;

double e(int x, int n) {
  static double p = 1, f = 1;
  double r;
  if (n == 0) {
    return 1;
  }
  r = e(x, n - 1);
  p = p * x;
  f = f * n;
  return r + p / f;
}

double e2(int x, int n) {
  static double s = 1;
  if (n == 0) {
    return s;
  }

  s = 1 + x * s / n;
  return e2(x, n - 1);
}

double e3(int x, int n) {
  double s = 1;
  for (; n > 0; n--) {
    s = 1 + x * s / n;
  }
  return s;
}

int main() {
  cout << e3(4, 20) << endl;
  return 0;
}