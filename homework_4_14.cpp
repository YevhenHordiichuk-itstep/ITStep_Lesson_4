#include <cstdio>
#include <stdlib.h>
#include <ctime>

void insertionSort(int A[], size_t SIZE) {
  for (size_t i = 1; i < SIZE; ++i) {
    int key = A[i];
    int k = i - 1;
    while (k >= 0 && A[k] > key) {
        int temp = A[k];
        A[k] = key;
        A[k + 1] = temp;
        --k;
    }
  }
}

bool binarySearch(int A[], size_t SIZE, int x) {
  size_t first = 0;
  size_t last = SIZE;
  if (SIZE == 0) {
    return false;
  } else if (A[0] > x) {
    return false;
  } else if (A[SIZE - 1] < x){
    return false;
  }
  
  while (first < last) {
    size_t mid = first + (last - first) / 2;
    if (x <= A[mid]) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }
  
  if (A[last] == x) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char** argv) {
  int array[16];
  size_t SIZE = sizeof(array) / sizeof(array[0]);
  const char* delimiter = "";
  srand(time(NULL));
  for (int i = 0; i < SIZE; ++i) {
    array[i] = (rand() % 100);
    printf("%s%i", delimiter, array[i]);
    delimiter = "_";
  }
  
  int X;
  printf("\nEnter X: ");
  scanf("%i", &X);
  
  insertionSort(array, SIZE);
  bool result = binarySearch(array, SIZE, X);
  if (result) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}