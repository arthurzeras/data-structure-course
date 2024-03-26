#include <iostream>

using namespace std;

/**
 * Tree recursion is when there's more than one call of the same function
 */
void function1(int x) {
  if (x > 0) {
    cout << x << " ";
    function1(x - 1);
    function1(x - 1);
  }
}

int main() {
  function1(5);
  cout << endl;
  return 0;
}