#include <iostream>

using namespace std;

// Using passing by value approach
// void swap(int x, int y) {
//   int temp = x;
//   x = y;
//   y = temp;
// }

// int main() {
//   int a = 10, b = 20;
//   swap(a, b);
//   cout << a << " " << b << endl;
//   return 0;
// }

// Using passing by pointers approach
// void swap(int *x, int *y) {
//   int temp = *x;
//   *x = *y;
//   *y = temp;
// }

// int main() {
//   int a = 10, b = 20;
//   swap(&a, &b);
//   cout << "a=" << a << " "
//        << "b=" << b << endl;
//   return 0;
// }

// Using passing by reference approach
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int a = 10, b = 20;
  swap(a, b);
  cout << "a=" << a << " "
       << "b=" << b << endl;
  return 0;
}