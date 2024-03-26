#include <iostream>

using namespace std;

// Initialized with garbage values
int A[5];

// initialized with default values
int A2[5] = {1, 2, 3, 4, 5};

// Initialized with some values
int A3[5] = {1, 2};

// Initialized with unknown size and initial values
int A4[] = {2, 2, 3, 4, 5};

int main() {
  printf("%d\n", A2[1]);
  printf("%d\n", 4 [A2]);
  printf("%d\n", *(A2 + 0));
  return 0;
}