#include <iostream>

using namespace std;

class Array {
private:
  int *A;
  int size;
  int length;
  void swap(int *x, int *y);

public:
  Array() {
    size = 10;
    length = 0;
    A = new int[size];
  }

  Array(int sz) {
    size = sz;
    length = 0;
    A = new int[size];
  }

  ~Array() { delete[] A; }

  /**
   * Display all Array members based on its length.
   */
  void display();

  /**
   * Add new element at the end (tail) of the Array.
   */
  void add(int value);

  /**
   * Insert new element into specific index of the Array and shift all other
   * elements if they exists.
   */
  void insert(int index, int value);

  /**
   * Insert new element into sorted Array.
   */
  void insertSort(int value);

  /**
   * Remove element based on its index and return it, also shift all the
   * remaning elements.
   */
  int remove(int index);

  /**
   * Perform a linear search (O(n)) in Array. Also it's possible to:
   * - Transposition: It will swap the element searched with the previous
   * one in order to increase the search time if the same value is searched
   * again.
   *
   * - Move to Head: It will swap the element searched with the first
   * element of the Array in order to increase the search time if the same value
   * is searched again.
   */
  int linearSearch(int key, bool transposition = false,
                   bool moveToHead = false);

  /**
   * Perform a binary search (O(log n)) in Array.
   */
  int binarySearch(int key);

  /**
   * Simply returns the element at the given index.
   */
  int get(int index);

  /**
   * Set the value of the element at the given index.
   */
  void set(int index, int value);

  /**
   * Return the max (greatest) element.
   */
  int max();

  /**
   * Return the min (smallest) element.
   */
  int min();

  /**
   * Return the sum of all elements.
   */
  int sum();

  /**
   * Return the average of all elements.
   */
  float avg();

  /**
   * Reverse the elements. If inPlace is true, it will change the original
   * Array, otherwise it will create a new Array.
   */
  void reverse(bool inPlace);

  /**
   * Remove first element, shift all other elements to the left and add a 0 to
   * last space.
   */
  int leftShift();

  /**
   * Remove last element, shift all other elements to the right and add a 0 to
   * first space.
   */
  int rightShift();

  /**
   * Rotate the Array to the left or to the right.
   */
  void rotate(bool right = false);

  /**
   * Check if the Array is sorted.
   */
  bool isSorted();

  /**
   * Rearrange the array moving all negative elements to left and positives to
   * right.
   */
  void rearrange();

  /**
   * Merge two sorted arrays into a new array.
   */
  Array *merge(Array arr);

  /**
   * Return the union (same elements in both) of two unsorted arrays (O(n^2)).
   */
  Array *unionUnsorted(Array arr);

  /**
   * Return the union (same elements in both) of two sorted arrays (O(n)).
   */
  Array *unionSorted(Array arr);

  /**
   * Return the intersection (different elements) of two unsorted arrays
   * (O(n^2)).
   */
  Array *intersectionUnsorted(Array arr);

  /**
   * Return the intersection (different elements) of two sorted arrays (O(n)).
   */
  Array *intersectionSorted(Array arr);
};

void Array::swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Array::display() {
  for (int i = 0; i < this->length; i++) {
    cout << this->A[i] << " ";
  }

  cout << endl;
}

void Array::add(int value) {
  if (this->length == this->size) {
    cout << "No enough space in array" << endl;
    return;
  }

  this->A[this->length] = value;
  this->length++;
}

void Array::insert(int index, int value) {
  if (index >= this->size || index < 0 || index > this->length) {
    cout << "Given index " << index << " is not valid." << endl;
    return;
  }

  for (int i = this->length; i > index; i--) {
    this->A[i] = this->A[i - 1];
  }

  this->A[index] = value;
  this->length++;
}

void Array::insertSort(int value) {
  if (this->isSorted() == false) {
    cout << "Array is not sorted" << endl;
    return;
  }

  if (this->length < this->size) {
    int i = this->length - 1;

    while (this->A[i] > value) {
      this->A[i + 1] = this->A[i];
      i--;
    }

    this->A[i + 1] = value;
    this->length++;
  }
}

int Array::remove(int index) {
  if (this->length == 0 || index >= this->length) {
    cout << "Can't remove, index out of range" << endl;
    return -1;
  }

  int x = this->A[index];

  this->length--;

  for (int i = index; i < this->length; i++) {
    this->A[i] = this->A[i + 1];
  }

  return x;
}

int Array::linearSearch(int key, bool transposition, bool moveToHead) {
  for (int i = 0; i < this->length; i++) {
    if (this->A[i] == key) {
      if (transposition) {
        this->swap(&this->A[i], &this->A[i - 1]);
        return i - 1;
      }

      if (moveToHead) {
        this->swap(&this->A[i], &this->A[0]);
        return 0;
      }

      return i;
    }
  }

  return -1;
}

int Array::binarySearch(int key) {
  if (this->isSorted() == false) {
    cout << "Array is not sorted" << endl;
    return -1;
  }

  int low = 0;
  int high = this->length;
  int mid = this->length / 2;

  while (low <= high) {
    if (this->A[mid] == key) {
      return mid;
    }

    if (this->A[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }

    mid = (low + high) / 2;
  }

  return -1;
}

int Array::get(int index) {
  if (index >= 0 && index < this->length) {
    return this->A[index];
  }
  return -1;
}

void Array::set(int index, int value) {
  if (index >= 0 && index < this->length) {
    this->A[index] = value;
  }
}

int Array::max() {
  int max = this->A[0];

  for (int i = 1; i < this->length; i++) {
    if (max < this->A[i]) {
      max = this->A[i];
    }
  }

  return max;
}

int Array::min() {
  int min = this->A[0];

  for (int i = 1; i < this->length; i++) {
    if (min > this->A[i]) {
      min = this->A[i];
    }
  }

  return min;
}

int Array::sum() {
  int sum = 0;

  for (int i = 0; i < this->length; i++) {
    sum += this->A[i];
  }

  return sum;
}

float Array::avg() {
  int sum = (float)this->sum();
  return sum / (float)this->length;
}

void Array::reverse(bool inPlace = false) {
  if (inPlace) {
    for (int i = 0; i < this->length / 2; i++) {
      int x = this->A[i];
      this->A[i] = this->A[this->length - 1 - i];
      this->A[this->length - 1 - i] = x;
    }
    return;
  }

  int B[this->length];

  for (int i = this->length - 1, j = 0; i >= 0; i--, j++) {
    B[j] = this->A[i];
  }

  for (int i = 0; i < this->length; i++) {
    this->A[i] = B[i];
  }
}

int Array::leftShift() {
  int x = this->A[0];

  for (int i = 0; i < this->length; i++) {
    this->A[i] = this->A[i + 1];
  }

  this->A[this->length - 1] = 0;

  return x;
}

int Array::rightShift() {
  int x = this->A[this->length - 1];

  for (int i = this->length - 1; i >= 0; i--) {
    this->A[i] = this->A[i - 1];
  }

  this->A[0] = 0;

  return x;
}

void Array::rotate(bool right) {
  int x;

  if (right) {
    x = this->rightShift();
    this->A[0] = x;
    return;
  }

  x = this->leftShift();
  this->A[this->length - 1] = x;
}

bool Array::isSorted() {
  for (int i = 0; i < this->length - 1; i++) {
    if (this->A[i] > this->A[i + 1]) {
      return false;
    }
  }
  return true;
}

void Array::rearrange() {
  int i = 0;
  int j = this->length;

  while (i < j) {
    while (this->A[i] < 0) {
      i++;
    }
    while (this->A[j] > 0) {
      j--;
    }

    if (i < j) {
      this->swap(&this->A[i], &this->A[j]);
    }
  }
}

Array *Array::merge(Array arr) {
  Array *result = new Array(this->length + arr.length);

  int i = 0, j = 0, k = 0;

  while (i < this->length && j < arr.length) {
    if (this->A[i] < arr.A[j]) {
      result->A[k++] = this->A[i++];
    } else {
      result->A[k++] = arr.A[j++];
    }
  }

  for (; i < this->length; i++) {
    result->A[k++] = this->A[i];
  }

  for (; j < arr.length; j++) {
    result->A[k++] = arr.A[j];
  }

  return result;
}

Array *Array::unionUnsorted(Array arr) {
  Array *result = new Array(this->length + arr.length);

  int i, j;

  for (i = 0; i < this->length; i++) {
    result->A[i] = this->A[i];
  }

  for (j = 0; j < arr.length; j++) {
    if (this->linearSearch(arr.A[j]) == -1) {
      result->A[i] = arr.A[j];
      result->length++;
      i++;
    }
  }

  return result;
}

Array *Array::unionSorted(Array arr) {
  Array *result = new Array(this->length + arr.length);

  int i = 0, j = 0, k = 0;

  while (i < this->length && j < arr.length) {
    result->length++;

    if (this->A[i] == arr.A[j]) {
      result->A[k++] = this->A[i++];
      j++;
      continue;
    }

    if (this->A[i] > arr.A[j]) {
      result->A[k++] = arr.A[j++];
      continue;
    }

    result->A[k++] = this->A[i++];
  }

  for (; i < this->length; i++) {
    result->length++;
    result->A[k++] = this->A[i];
  }

  for (; j < this->length; j++) {
    result->length++;
    result->A[k++] = arr.A[j];
  }

  return result;
}

Array *Array::intersectionUnsorted(Array arr) {
  Array *result = new Array(this->length + arr.length);

  int k = 0;

  for (int i = 0; i < this->length; i++) {
    if (this->linearSearch(arr.A[i]) != -1) {
      result->A[k++] = arr.A[i];
      result->length++;
    }
  }

  return result;
}

Array *Array::intersectionSorted(Array arr) {
  Array *result = new Array(this->length + arr.length);

  int i = 0, j = 0, k = 0;

  while (i < this->length && j < arr.length) {
    if (this->A[i] == arr.A[j]) {
      result->A[k++] = this->A[i++];
      result->length++;
      j++;
      continue;
    }

    if (this->A[i] < arr.A[j]) {
      i++;
      continue;
    }

    j++;
  }

  return result;
}

int main() { return 0; }