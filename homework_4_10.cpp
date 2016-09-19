#include <cstdio>
#include <cstring>

int main(int argc, char** argv) {
  int i;
  char* str;
  scanf("%s", str);
  for (i = (strlen(str) - 1); i >= 0 ; --i) {
    printf("%c", str[i]);
  }
  return 0;
}