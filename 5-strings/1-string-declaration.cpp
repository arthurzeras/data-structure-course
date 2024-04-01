#include <iostream>

int main() {
  char name1[10] = {'J', 'o', 'h', 'n', '\0'};

  char name2[] = {'J', 'o', 'h', 'n', '\0'};

  char name3[] = "John";

  // Print char
  printf("%c\n", name1[0]);

  // Print string
  printf("%s\n", name3);
  return 0;

  // Get string from input. This will take only one word
  scanf("%s", name1);
}