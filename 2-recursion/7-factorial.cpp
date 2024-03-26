#include <iostream>

using namespace std;

int factorialRecursive(int n) {
  if (n == 0) {
    return 1;
  }

  return factorialRecursive(n - 1) * n;
}

int factorialLoop(int n) {
  int r = 1;

  for (int i = 1; i <= n; i++) {
    r = r * i;
  }

  return r;
}

int main() {
  int n = 11;
  cout << "factorial of " << n << " is " << factorialLoop(n) << endl;

  return 0;
}