#include <iostream>

using namespace std;

void function2(int n);

void function1(int n) {
  if (n > 0) {
    cout << n << " ";
    function2(n - 1);
  }
}

void function2(int n) {
  if (n > 1) {
    cout << n << " ";
    function1(n / 2);
  }
}

int main() {
  function1(20);
  return 0;
}