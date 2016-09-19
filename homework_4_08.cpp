#include <cstdio>

int main(int argc, char** argv) {
  char insert[32];
  const size_t SIZE = 5;
  for (;;) {
    size_t index = 0;
    printf("Enter 5 different letters from 'a' to 'z': ");
    scanf("%s", insert);
    if (insert[SIZE] == '\0') {
      break;
    }
    printf("Uncorrect exception, try again\n");
  }
  
  char buffer[] = "aaaaa";
  char* a = &buffer[0];
  char* b = &buffer[1];
  char* c = &buffer[2];
  char* d = &buffer[3];
  char* e = &buffer[4];
  for (size_t i = 0; i < SIZE; ++i) {
    *a = insert[i];
    for (size_t j = 0; j < SIZE; ++j) {
      *b = insert[j];
      for (size_t k = 0; k < SIZE; ++k) {
        *c = insert[k];
        for (size_t n = 0; n < SIZE; ++n) {
          *d = insert[n];
          for (size_t m = 0; m < SIZE; ++m) {
            *e = insert[m];
            if (i != j && i != k && i != m && i != n && j != k && j != m && j != n && k != m && k != n && m != n) {
              printf("%s\n", buffer);
             
            }
          }
        }
      }
    }
  }
  return 0;
}