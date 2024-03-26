#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Enter a size" << endl;
  cin >> n;

  int a[n];

  a[0] = 1;
  a[1] = 4;
  a[2] = 6;

  // cout << sizeof(a) << endl;
  for (int x : a) {
    printf("%d\n", x);
  }

  return 0;

  // for (int i = 0; i < 5; i++) {
  //   printf("%d\n", a[i]);
  // }
}