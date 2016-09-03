#include <cstdio>  //приложение к "Easy_Task_1" задача 2 Палиндром. Хотелось бы чтобы проверка на палиндром проходила даже если есть пробелы в строке!

void palindrom(char str[], int SIZE) {
  int n = 0;
  char strclean[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    if (str[i] != ' ') {
      strclean[n] = str[i];
      ++n;
    }
  }
  
  for (int i = 0; i < n; ++i) {
  if (strclean[i] != strclean[n - 1 - i]) {
      printf("No");
      return;
    }
  }
  printf("Yes!");
}

int main(int argc, char** argv) {
  char str[100];
  int N = sizeof(str) / sizeof(str[0]);
  for (int i = 0; i < N; ++i) {
    scanf("%c", &str[i]);
    if (str[i] == '\n') {
      str[i] = EOF;
      N = i;
    }
  }
  palindrom(str, N);
  return 0;
}