#include <iostream>

using namespace std;

class DiagonalMatrix {
private:
  int size;
  int *arr;

public:
  DiagonalMatrix(int size) {
    this->size = size;
    this->arr = new int[size];
  }

  ~DiagonalMatrix() { delete[] this->arr; }

  void set(int x, int y, int val) {
    if (x == y) {
      this->arr[x - 1] = val;
    }
  }

  int get(int x, int y) {
    if (x == y) {
      return this->arr[x - 1];
    }
    return 0;
  }

  void display() {
    for (int i = 0; i < this->size; i++) {
      for (int j = 0; j < this->size; j++) {
        if (i == j) {
          cout << " " << this->arr[i - 1] << " ";
        } else {
          cout << " 00 ";
        }
      }
      cout << endl;
    }
  }
};

int main() {
  DiagonalMatrix matrix(5);

  matrix.set(0, 0, 10);
  matrix.set(1, 1, 12);
  matrix.set(2, 2, 13);
  matrix.set(3, 3, 14);
  matrix.set(4, 4, 17);

  matrix.display();

  return 0;
}