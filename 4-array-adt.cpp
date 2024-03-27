#include <iostream>

using namespace std;

struct Array {
  int A[10];
  int size;
  int length;
};

void Display(Array *arr) {
  for (int i = 0; i < arr->length; i++) {
    cout << arr->A[i] << " ";
  }

  cout << endl;
}

void Add(Array *arr, int value) {
  if (arr->length == arr->size) {
    printf("No enough space in array\n");
    return;
  }

  arr->A[arr->length] = value;
  arr->length++;
}

void Insert(Array *arr, int index, int value) {
  if (index >= arr->size || index < 0 || index > arr->length) {
    printf("Given index %d is not valid\n", index);
    return;
  }

  for (int i = arr->length; i > index; i--) {
    arr->A[i] = arr->A[i - 1];
  }

  arr->A[index] = value;
  arr->length++;
}

void InsertSorted(Array *arr, int value) {
  if (arr->length < arr->size) {
    int i = arr->length - 1;

    while (arr->A[i] > value) {
      arr->A[i + 1] = arr->A[i];
      i--;
    }

    arr->A[i + 1] = value;
    arr->length++;
  }
}

int Delete(Array *arr, int index) {
  if (arr->length == 0 || index >= arr->length) {
    printf("Can't delete \n");
    return -1;
  }

  int x = arr->A[index];

  arr->length--;

  for (int i = index; i < arr->length; i++) {
    arr->A[i] = arr->A[i + 1];
  }

  return x;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch(Array *arr, int key, bool useTransposition = false,
                 bool useMoveToHead = false) {

  for (int i = 0; i < arr->length; i++) {
    if (arr->A[i] == key) {
      if (useTransposition) {
        swap(&arr->A[i], &arr->A[i - 1]);
        return i - 1;
      }

      if (useMoveToHead) {
        swap(&arr->A[i], &arr->A[0]);
        return 0;
      }

      return i;
    }
  }

  return -1;
}

int BinarySearch(Array *arr, int key) {
  int low = 0;
  int high = arr->length;
  int mid = arr->length / 2;

  while (low <= high) {
    if (arr->A[mid] == key) {
      return mid;
    }

    if (arr->A[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }

    mid = (low + high) / 2;
  }

  return -1;
}

int Get(Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.A[index];
  }
  return -1;
}

void Set(Array *arr, int index, int value) {
  if (index >= 0 && index < arr->length) {
    arr->A[index] = value;
  }
}

int Max(Array arr) {
  int max = arr.A[0];

  for (int i = 1; i < arr.length; i++) {
    if (max < arr.A[i]) {
      max = arr.A[i];
    }
  }

  return max;
}

int Min(Array arr) {
  int min = arr.A[0];

  for (int i = 1; i < arr.length; i++) {
    if (min > arr.A[i]) {
      min = arr.A[i];
    }
  }

  return min;
}

int Sum(Array arr) {
  int sum = 0;

  for (int i = 0; i < arr.length; i++) {
    sum += arr.A[i];
  }

  return sum;
}

float Avg(Array arr) {
  int sum = (float)Sum(arr);
  return sum / (float)arr.length;
}

void Reverse(Array *arr, bool inPlace = false) {
  if (inPlace) {
    for (int i = 0; i < arr->length / 2; i++) {
      int x = arr->A[i];
      arr->A[i] = arr->A[arr->length - 1 - i];
      arr->A[arr->length - 1 - i] = x;
    }
    return;
  }

  int B[arr->length];

  for (int i = arr->length - 1, j = 0; i >= 0; i--, j++) {
    B[j] = arr->A[i];
  }

  for (int i = 0; i < arr->length; i++) {
    arr->A[i] = B[i];
  }
}

int LeftShift(Array *arr) {
  int x = arr->A[0];
  for (int i = 0; i < arr->length; i++) {
    arr->A[i] = arr->A[i + 1];
  }
  arr->A[arr->length - 1] = 0;
  return x;
}

int RightShift(Array *arr) {
  int x = arr->A[arr->length - 1];
  for (int i = arr->length - 1; i >= 0; i--) {
    arr->A[i] = arr->A[i - 1];
  }
  arr->A[0] = 0;
  return x;
}

void Rotate(Array *arr, bool right = false) {
  int x;

  if (right) {
    x = RightShift(arr);
    arr->A[0] = x;
    return;
  }

  x = LeftShift(arr);
  arr->A[arr->length - 1] = x;
}

bool IsSorted(Array arr) {
  for (int i = 0; i < arr.length - 1; i++) {
    if (arr.A[i] > arr.A[i + 1]) {
      return false;
    }
  }
  return true;
}

void MoveNegativesForLeftSide(Array *arr) {
  int i = 0;
  int j = arr->length;

  while (i < j) {
    while (arr->A[i] < 0) {
      i++;
    }
    while (arr->A[j] > 0) {
      j--;
    }

    if (i < j) {
      swap(&arr->A[i], &arr->A[j]);
    }
  }
}

Array *Merge(Array m, Array n) {
  Array *result = new Array;
  result->length = m.length + n.length;
  result->size = m.size + n.size;

  int i = 0, j = 0, k = 0;

  while (i < m.length && j < n.length) {
    if (m.A[i] < n.A[j]) {
      result->A[k++] = m.A[i++];
    } else {
      result->A[k++] = n.A[j++];
    }
  }

  for (; i < m.length; i++) {
    result->A[k++] = m.A[i];
  }

  for (; j < n.length; j++) {
    result->A[k++] = n.A[j];
  }

  return result;
}

Array *UnionUnsorted(Array m, Array n) {
  Array *result = new Array;
  result->length = m.length;

  int i;

  for (i = 0; i < m.length; i++) {
    result->A[i] = m.A[i];
  }

  for (int j = 0; j < n.length; j++) {
    if (LinearSearch(&m, n.A[j]) == -1) {
      result->A[i] = n.A[j];
      result->length++;
      i++;
    }
  }

  return result;
}

Array *UnionSorted(Array m, Array n) {
  Array *result = new Array;
  result->length = 0;

  int i = 0, j = 0, k = 0;

  while (i < m.length && j < n.length) {
    result->length++;

    if (m.A[i] == n.A[j]) {
      result->A[k++] = m.A[i++];
      j++;
      continue;
    }

    if (m.A[i] > n.A[j]) {
      result->A[k++] = n.A[j++];
      continue;
    }

    result->A[k++] = m.A[i++];
  }

  for (; i < m.length; i++) {
    result->length++;
    result->A[k++] = m.A[i];
  }

  for (; j < m.length; j++) {
    result->length++;
    result->A[k++] = n.A[j];
  }

  return result;
}

Array *IntersectionUnsorted(Array m, Array n) {
  Array *result = new Array;
  result->length = 0;

  int k = 0;

  Array largestArray = m;
  Array smallestArray = n;

  if (m.length < n.length) {
    largestArray = n;
    smallestArray = m;
  }

  for (int i = 0; i < largestArray.length; i++) {
    if (LinearSearch(&smallestArray, largestArray.A[i]) != -1) {
      result->A[k++] = largestArray.A[i];
      result->length++;
    }
  }

  return result;
}

Array *IntersectionSorted(Array m, Array n) {
  Array *result = new Array;

  int i = 0, j = 0, k = 0;

  while (i < m.length && j < n.length) {
    if (m.A[i] == n.A[j]) {
      result->A[k++] = m.A[i++];
      result->length++;
      j++;
      continue;
    }

    if (m.A[i] < n.A[j]) {
      i++;
      continue;
    }

    j++;
  }

  return result;
}

int main() {
  // Array arr = {{2, 3, 4, 5, 6}, 10, 5};

  // Display(&arr);
  // Add(&arr, 7);
  // Add(&arr, 8);
  // Add(&arr, 9);
  // Display(&arr);
  // Insert(&arr, 0, 1);
  // Display(&arr);
  // int deleted = Delete(&arr, 2);
  // printf("Element deleted: %d \n", deleted);
  // Display(&arr);
  // int index = LinearSearch(&arr, 6, true);
  // printf("Element found at index: %d \n", index);
  // Display(&arr);

  // int binarySearchResult = BinarySearch(&arr, 9);
  // printf("Binary search element found at index: %d \n", binarySearchResult);

  // printf("Max element is %d\n", Max(arr));
  // printf("Min element is %d\n", Min(arr));
  // printf("Sum of elements is %d\n", Sum(arr));
  // printf("Avg of elements is %f\n", Avg(arr));

  // Reverse(&arr);
  // printf("Reversed array: ");
  // Display(&arr);

  // Reverse(&arr, true);
  // printf("Reversed array in place: ");
  // Display(&arr);

  // LeftShift(&arr);
  // printf("Array left shifted: ");
  // Display(&arr);

  // RightShift(&arr);
  // printf("Array right shifted: ");
  // Display(&arr);

  // Rotate(&arr, true);
  // printf("Array left rotated: ");
  // Display(&arr);

  // Rotate(&arr, true);
  // printf("Array right rotated: ");
  // Display(&arr);

  // InsertSorted(&arr, 3);
  // printf("Number 3 sorted inserted: ");
  // Display(&arr);
  // printf("Array is sorted? %d\n", IsSorted(arr));

  // Array arr2 = {{-2, 3, 14, 5, -6, 10, -5, 22, 1, -8}, 10, 10};
  // printf("Negatives moved for the left side: ");
  // MoveNegativesForLeftSide(&arr2);
  // Display(&arr2);

  // Array arr1 = {{2, 5, 8, 10, 16}, 10, 5};
  // Array arr2 = {{1, 3, 14, 21, 23}, 10, 5};

  // printf("-------------------\n");
  // printf("arr1: ");
  // Display(&arr1);
  // printf("arr2: ");
  // Display(&arr2);

  // Array *mergedArr = Merge(arr1, arr2);
  // printf("Arrays merged: ");
  // Display(mergedArr);

  // Array arr1 = {{2, 8, 10, 16, 5}, 10, 5};
  // Array arr2 = {{2, 21, 3, 10, 8}, 10, 5};

  // Array *unionArr = UnionUnsorted(arr1, arr2);
  // printf("Arrays union: ");
  // Display(unionArr);

  // Array arr1 = {{2, 5, 8, 10, 16}, 10, 5};
  // Array arr2 = {{1, 3, 8, 16, 23}, 10, 5};

  // Array *unionSortedArr = UnionSorted(arr1, arr2);
  // printf("Arrays union: ");
  // Display(unionSortedArr);

  // Array arr1 = {{2, 8, 10, 16, 5}, 10, 5};
  // Array arr2 = {{2, 21, 3, 10, 8}, 10, 5};

  // Array *intersectionUnsortedArr = IntersectionUnsorted(arr1, arr2);
  // printf("Arrays intersection: ");
  // Display(intersectionUnsortedArr);

  Array arr1 = {{2, 5, 8, 10, 16}, 10, 5};
  Array arr2 = {{1, 3, 8, 16, 23}, 10, 5};

  Array *intersectionSortedArr = IntersectionSorted(arr1, arr2);
  printf("Arrays intersection: ");
  Display(intersectionSortedArr);

  return 0;
}