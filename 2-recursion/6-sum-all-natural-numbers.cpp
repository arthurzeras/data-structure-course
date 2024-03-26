#include <iostream>

using namespace std;

int sumNumbers(int n) {
  if (n == 0) {
    return 0;
  }

  return sumNumbers(n - 1) + n;
}

int sumNumbersAsLoop(int n) {
  int i, s = 0;
  while (i <= n) {
    s = s + i;
    i++;
  }
  return s;
}

int main() {
  int n = 4;
  cout << "sum of " << n << " is " << sumNumbersAsLoop(n) << endl;
}