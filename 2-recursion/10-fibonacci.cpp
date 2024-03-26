#include <iostream>

using namespace std;
int a[100];

int fib(int n) {
  if (n <= 1) {
    return n;
  }

  return fib(n - 2) + fib(n - 1);
}

int fib2(int n) {
  int t0 = 0, t1 = 1, s;
  for (int i = 2; i <= n; i++) {
    s = t0 + t1;
    t0 = t1;
    t1 = s;
  }
  return s;
}

// Memoization
int fib3(int n) {
  if (n <= 1) {
    a[n] = n;
    return n;
  }

  // cout << a[n - 2] << " ";

  if (a[n - 2] == -1) {
    a[n - 2] = fib3(n - 2);
  }

  if (a[n - 1] == -1) {
    a[n - 1] = fib3(n - 1);
  }

  return a[n - 2] + a[n - 1];
}

int main() {
  for (int i = 0; i < 10; i++) {
    a[i] = -1;
  }

  cout << fib3(7) << endl;
  return 0;
}