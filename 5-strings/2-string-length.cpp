#include <iostream>

using namespace std;

// get the length of string
int strlen(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; ++i) {
  };
  return i;
}

int main() {
  char example[] = "Hello World";

  cout << "Length of string: " << strlen(example) << endl;

  return 0;
}