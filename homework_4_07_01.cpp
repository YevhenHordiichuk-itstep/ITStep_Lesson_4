#include <cstdio>

int main(int argc, char** argv) {
  char pass[] = {'a', 'b', 'c', 'd', 'e'};
  size_t SIZE = sizeof(pass) / sizeof(pass[0]);
  char buffer[] = "aaaaa";
  char* c0 = &buffer[0];
  char* c1 = &buffer[1];
  char* c2 = &buffer[2];
  char* c3 = &buffer[3];
  char* c4 = &buffer[4];
  for (int i = 0; i < SIZE; ++i) {
    *c0 = pass[i];
    for (int j = 0; j < SIZE; ++j) {
      *c1 = pass[j];
      for (int k = 0; k < SIZE; ++k) {
        *c2 = pass[k];
        for (int n = 0; n < SIZE; ++n) {
          *c3 = pass[n];
          for (int m = 0; m < SIZE; ++m) {
            *c4 = pass[m];
            printf("%s\n", buffer);
          }
        }
      }
    }
  }
  return 0;
}