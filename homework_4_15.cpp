#include <cstdio>
#include <cstring>
#include <algorithm>

void insertionSortLex(char* str[], size_t SIZE) {
  for (int i = 1; i < SIZE; ++i) {
    char* key = str[i];
    int j = i - 1;
    while (j >= 0 && strcmp(str[j][0], key) > 0) {
      char* temp = str[j];
      str[j] = key;
      str[j + 1] = temp;
      --j;
      }
  }
}

void print(char* str[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    printf("%s ", str[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  char* dictionary[] = {"mathematics", "biology", "physics", "psychology", "geometry", 
                        "geography", "geology", "bioinformatics", "science", "scifi", 
                        "pharmacology", "musics", "analysis", "policy", "geopolicy", 
                        "politology", "demonology", "demonstations", "bioengineering",
                        "modeling", "algebra", "literature", "liberation", "listing", 
                        "society", "scene", "lighting"};
  size_t SIZE = sizeof(dictionary) / sizeof(dictionary[0]);
  insertionSortLex(dictionary, SIZE);
  print(dictionary, SIZE);
  return 0;
}