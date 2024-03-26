#include <iostream>

using namespace std;

int example(int n) {
  if (n > 100) {
    return n - 10;
  }
  return example(example(n + 11));
}

int main() {
  cout << example(95);
  return 0;
}