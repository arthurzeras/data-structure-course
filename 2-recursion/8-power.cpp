#include <iostream>

using namespace std;

int pow(int m, int n) {
  if (n == 0) {
    return 1;
  }

  return pow(m, n - 1) * m;
}

int pow2(int m, int n) {
  if (n == 0) {
    return 1;
  }

  if (n % 2 == 0) {
    return pow(m * m, n / 2);
  }

  return m * pow(m * m, (n - 1) / 2);
}

int powLoop(int m, int n) {
  int r = 1;
  for (int i = n; i > 0; i--) {
    r = m * r;
  }
  return r;
}

int main() {
  cout << powLoop(9, 3) << endl;
  return 0;
}