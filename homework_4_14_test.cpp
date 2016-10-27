// homework_4_14_test_fixed

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <windows.h>

void insertionSort(int array[], size_t SIZE) {
  for (size_t i = 1; i < SIZE; ++i) {
    int key = array[i];
    int k = i - 1;
    while (k >= 0 && array[k] > key) {
        int temp = array[k];
        array[k] = key;
        array[k + 1] = temp;
        --k;
    }
  }
}

bool binarySearch(int array[], size_t SIZE, int x) {
  size_t first = 0;
  size_t last = SIZE;
  if (SIZE == 0) {
    return false;
  } else if (x < array[first]) {
    return false;
  } else if (x > array[SIZE - 1]){
    return false;
  } else if (x == array[first]) {
    return true;
  } else if (x == array[SIZE - 1]) {
    return true;
  }
  
  while (first < last) {
  size_t mid = first + (last - first) / 2;
    if (x <= array[mid]) {
      last = mid;                    
    } else {
      first = mid + 1;            
    }
  } 
  
  return array[last] == x;
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
  double seconds = (double) NULL;
  clock_t start = clock();
  while(seconds < 5.0) {
    srand(GetTickCount() + rand());
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
    clock_t elapsed = clock() - start;
    seconds = (double) elapsed / CLOCKS_PER_SEC;
  }
  return 0;
}