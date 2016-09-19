#include <cstdio>

int main(int argc, char** argv) {
  const char* dictionary[] = {"mathematics", "physics", "biology", "psychology", "geometry", "geography", 
            "geology", "bioinformatics", "science", "scifi", "pharmacology", "musics", "analysis", 
            "policy", "geopolicy", "politology", "demonology", "demonstations", "bioengineering", 
            "modeling", "algebra", "literature", "liberation", "listing", "society", "scene", "lighting"};
  size_t SIZE = sizeof(dictionary) / sizeof(dictionary[0]);
  
  char key_search[32];
  size_t SIZE_key = sizeof(key_search) / sizeof(key_search[0]);
  printf("enter key search: ");
  for (size_t i = 0; i < SIZE_key; ++i) {
    scanf("%c", &key_search[i]);
    if (key_search[i] == '\n') {
      key_search[i] = '\0';
      SIZE_key = i;
      break;
    }  
  }
  
  const char* delimiter = "";
  for (size_t i = 0; i < SIZE; ++i) {
    for (size_t n = 0; n < SIZE_key; ++n) {
      if (key_search[n] != dictionary[i][n]) {
        break;
      }
      if (n == SIZE_key - 1) {
        printf("%s%s", delimiter, dictionary[i]);
        delimiter = ", ";
      }
    }
  }
  return 0;
}