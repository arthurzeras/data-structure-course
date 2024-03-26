#include <iostream>

int main() {
  int *p = new int[5]; // Create an array with size of 5
  for (int i = 0; i < 5; i++) {
    p[i] = i + 1;
  }

  for (int i = 0; i < 5; i++) {
    printf("%d\n", p[i]);
  }

  // Increate size by creating new pointer with array with new size and change
  // the previous pointer to it

  int *temporary_pointer = new int[10];

  for (int i; i < 5; i++) {
    temporary_pointer[i] = p[i];
  }

  delete[] p;
  p = temporary_pointer;
  temporary_pointer = NULL;

  printf("---------\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", p[i]);
  }

  // printf("%d\n", p);
  // printf("%d\n", temporary_pointer);

  return 0;
}