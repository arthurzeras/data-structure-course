#include <iostream>

using namespace std;

/**
 *  Get the length of string
 */
int strlen(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; ++i) {
  };
  return i;
}

/**
 * Tranform uppercases to lowercases and vice-versa
 */
void invertCapital(char *str) {
  int i;

  for (i = 0; str[i] != '\0'; ++i) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
      continue;
    }
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    }
  };
}

void toLowerCase(char *str) {
  int i;

  for (i = 0; str[i] != '\0'; ++i) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    }
  };
}

void countCharacters(char *str) {
  int i, consonantCounter = 0, vowelCounter = 0;

  for (i = 0; str[i] != '\0'; ++i) {
    if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
        str[i] == 'U' || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
        str[i] == 'o' || str[i] == 'u') {
      vowelCounter++;
      continue;
    }

    if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
      consonantCounter++;
      continue;
    }
  };

  cout << "Vowels: " << vowelCounter << endl;
  cout << "Consonants: " << consonantCounter << endl;
}

void countWords(char *str) {
  int i, wordCounter = 1;

  for (i = 0; str[i] != '\0'; ++i) {
    if (str[i] == ' ' && str[i - 1] != ' ') {
      wordCounter++;
    }
  };

  cout << "Total worlds: " << wordCounter << endl;
}

bool isValid(char *str) {
  for (int i = 0; str[i] != '\0'; ++i) {
    if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) &&
        !(str[i] >= 48 && str[i] <= 57)) {
      return false;
    }
  }
  return true;
}

void reverse(char *str) {
  int len = strlen(str);
  len--;

  for (int i = 0; i < len; i++, len--) {
    char temp = str[i];
    str[i] = str[len];
    str[len] = temp;
  }
}

bool isEqual(char *str, char *compare) {
  for (int i = 0, j = 0; str[i] != '\0'; i++, j++) {
    if (str[i] != compare[j]) {
      return false;
    }
  }
  return true;
}

bool isPalindrome(char *str) {
  int j = strlen(str);
  j--;
  for (int i = 0; i < j; i++, j--) {
    if (str[i] != str[j]) {
      return false;
    }
  }
  return true;
}

void findDuplicate(char *str) {
  int h = 0, x = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    x = 1;
    x = x << (str[i] - 97); // Shift left

    if ((x & h) > 0) { // Masking (bitwise AND)
      cout << str[i] << " is duplicate" << endl;
    } else {
      h = x | h; // Merging (bitwise OR)
    }
  }
}

int main() {
  char example[] = "Hello World";
  char example2[] = "ValidString";
  char example3[] = "madam";

  cout << "Length of string: " << strlen(example) << endl;
  invertCapital(example);
  cout << "Inverted capital: " << example << endl;
  countCharacters(example);
  countWords(example);
  cout << "Is valid: " << isValid(example) << endl;
  cout << "Is valid: " << isValid(example2) << endl;

  reverse(example);
  cout << "Reversed string: " << example << endl;
  cout << "Is equal: " << isEqual(example, example) << endl;
  cout << "Is palindrome: " << isPalindrome(example3) << endl;
  toLowerCase(example);
  findDuplicate(example);

  return 0;
}