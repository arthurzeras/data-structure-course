#include <iostream>

using namespace std;

class LowerTriangularMatrix {
private:
  int size;
  int *arr;

public:
  LowerTriangularMatrix(int size) {
    this->size = size;
    this->arr = new int[size * (size + 1) / 2];
  }

  ~LowerTriangularMatrix() { delete[] this->arr; }

  void set(int x, int y, int val) {
    if (x >= y) {
      this->arr[x * (x - 1) / 2 + y - 1] = val;
    }
  }

  int get(int x, int y) {
    if (x >= y) {
      return this->arr[x * (x - 1) / 2 + y - 1];
    }
    return 0;
  }

  void display() {
    for (int i = 1; i <= this->size; i++) {
      for (int j = 1; j <= this->size; j++) {
        if (i >= j) {
          cout << " " << this->arr[i * (i - 1) / 2 + j - 1] << " ";
        } else {
          cout << " 00 ";
        }
      }
      cout << endl;
    }
  }
};

int main() {
  int dimension = 5;
  LowerTriangularMatrix matrix(dimension);

  matrix.set(1, 1, 10);
  matrix.set(2, 1, 12);
  matrix.set(2, 2, 13);
  matrix.set(3, 1, 14);
  matrix.set(3, 2, 15);
  matrix.set(3, 3, 16);
  matrix.set(4, 1, 17);
  matrix.set(4, 2, 18);
  matrix.set(4, 3, 18);
  matrix.set(4, 4, 19);
  matrix.set(5, 1, 20);
  matrix.set(5, 2, 21);
  matrix.set(5, 3, 22);
  matrix.set(5, 4, 22);
  matrix.set(5, 5, 24);

  matrix.display();

  /*
   It'll print:
   10  00  00  00  00
   12  13  00  00  00
   14  15  16  00  00
   17  18  18  19  00
   20  21  22  22  24
  */

  return 0;
}