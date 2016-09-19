#include <cstdio>

int main(int argc, char** argv) {
  char password[] = "abcde";
  size_t SIZE = sizeof(password) / sizeof(password[0]) - 1;
  for (size_t i = 0; i < SIZE; ++i) {
    for (size_t j = 0; j < SIZE; ++j) {
      for (size_t k = 0; k < SIZE; ++k) {
        for (size_t n = 0; n < SIZE; ++n) {
          for (size_t m = 0; m < SIZE; ++m) {
            printf("%c%c%c%c%c\n", password[i], password[j], password[k], password[n], password[m]);
          }
        }
      }
    }
  }
  return 0;
}