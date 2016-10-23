// homework_4_14_test 

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>

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
  } else if (x < A[first]) {
    return false;
  } else if (x > A[SIZE - 1]){
    return false;
  } else if (x == A[first]) {
    return true;
  } else if (x == A[SIZE - 1]) {
    return true;
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

void generate(int array[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    array[i] = rand() % 20;
  }
}

void arrayCopy(int array[], int copy[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    copy[i] = array[i];
  }
}
void printarray(int array[], size_t SIZE) {
  const char* delimiter = "array = [";
  for (size_t i = 0; i < SIZE; ++i) {
    printf("%s%i", delimiter, array[i]);
    delimiter = ", ";
  }
  printf("]\n");
}

int main(int argc, char** argv) {
  while(true) {
    //srand(time(NULL));
    srand(GetTickCount());
    size_t SIZE = rand() % 14 + 1;
    int array[SIZE];
    int copy[SIZE];
    int x = rand() % 20;
    generate(array, SIZE);
    arrayCopy(array, copy, SIZE);
    
    insertionSort(array, SIZE);
    std::sort(copy, copy + SIZE);
    
    if (binarySearch(array, SIZE, x) == std::binary_search(copy, copy + SIZE, x)) {
      printf("OK\n");
      printf("X = %i\n", x);
      printarray(array, SIZE);
    } else {
      printf("Error!\a\nX = %i\n", x);
      printarray(array, SIZE);
      break;
    }
    
  }
  return 0;
}