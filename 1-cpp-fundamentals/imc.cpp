#include <cmath>
#include <iostream>

using namespace std;

int main() {
  float h = 1.80;
  float w = 80.1;

  cout << "Digite sua altura: ";
  cin >> h;

  cout << "Digite seu peso: ";
  cin >> w;

  float imc = w / pow(h, 2);

  if (imc < 18.8) {
    cout << "Abaixo do peso" << endl;
  } else if (imc < 25) {
    cout << "Peso normal" << endl;
  } else if (imc < 30) {
    cout << "Acima do peso" << endl;
  } else if (imc < 35) {
    cout << "Obesidade I" << endl;
  } else if (imc < 40) {
    cout << "Obesidade II" << endl;
  } else {
    cout << "Obesidade III" << endl;
  }

  return 0;
}