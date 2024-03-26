#include <iostream>

using namespace std;

int main() {
  // Define in stack memory
  int A[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {5, 4, 1, 3}};

  // Define partially in stack memory and partially in heap memory
  int *B[3];
  B[0] = new int[4];
  B[1] = new int[4];
  B[2] = new int[4];

  // Define completely in heap memory with two pointers
  int **C = new int *[3];
  C[0] = new int[4];
  C[1] = new int[4];
  C[2] = new int[4];

  // Access values
  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 4; j++) {
  //     cout << A[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << A << " | " << A + 1 << endl;

  return 0;
}