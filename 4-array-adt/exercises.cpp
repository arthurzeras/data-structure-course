#include <iostream>

using namespace std;

struct Array {
  int *A;
  int size;
  int length;
};

/**
 * Find a single missing element in sorted Array.
 */
int findSingleMissingElement(Array *arr) {
  int i = 0;
  int lower = arr->A[0];

  while (lower == arr->A[0] && i < arr->length) {
    lower = arr->A[i] - i;
    i++;
  }

  return arr->A[i - 1] - 1;
}
