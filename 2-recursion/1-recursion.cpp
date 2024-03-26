#include <iostream>

using namespace std;

void function1(int x) {
  if (x > 0) {
    cout << x << endl;
    function1(x - 1);
  }
}

int main() {
  function1(10);
  return 0;
}