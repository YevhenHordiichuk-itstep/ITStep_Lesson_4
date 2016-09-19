#include <cstdio>

int main(int argc, char** argv) {
  char buffer[100];
  size_t SIZE = sizeof(buffer) / sizeof(buffer[0]);
  char* pointer = buffer;
  for (int i = 0; i < SIZE; ++i) {
    scanf("%c", pointer + i);
    if (pointer[i] == '\n') {
      pointer[i] = '\0';
      SIZE = i;
      break;
    }
  }
  printf("%s\t", pointer);
  for (int i = 1; i <= SIZE; ++i) {
    printf("%c", pointer[SIZE - i]);
  }
  return 0;
}