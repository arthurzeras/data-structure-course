#include <iostream>

using namespace std;

template <class T> class Arithmetic {
private:
  T a, b;

public:
  Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
  }

  T add() { return a + b; }

  T sub() { return a - b; }
};

int main() {
  Arithmetic<int> aint(5, 2);
  cout << "Sum: " << aint.add() << endl;
  cout << "Sub: " << aint.sub() << endl;

  Arithmetic<float> afloat(5.1, 2.8);
  cout << "Sum: " << afloat.add() << endl;
  cout << "Sub: " << afloat.sub() << endl;

  return 0;
}