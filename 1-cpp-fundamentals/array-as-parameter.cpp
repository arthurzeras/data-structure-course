#include <iostream>

using namespace std;

/**
 * - Cannot pass array by value or reference, only pointers (address)
 * - Cannot perform a foreach (for (int x:a)) loop inside function because it's
 * a pointer
 * - Also it's possible to use the * operator in parameter because arrays as
 * parameters is always a pointer
 */
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int *initializeArray(int size) {
  int *p = new int[size];

  for (int i = 0; i < size; i++) {
    p[i] = i + 1;
  }

  return p;
}

int main() {
  // int a[] = {1, 2, 3, 4, 5};
  int length = 5;
  int *a = initializeArray(length);
  printArray(a, length);
}