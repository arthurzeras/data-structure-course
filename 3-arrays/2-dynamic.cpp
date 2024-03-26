#include <iostream>

int main() {
  int A[5] = {}; // Array in stack memory (local)
  int *P;
  P = new int[5]; // Array created in heap memory using a pointer

  // Assign values to array
  A[2] = 9;
  P[2] = 20;

  printf("%d\n", A[2]);
  printf("%d\n", P[2]);

  return 0;
}