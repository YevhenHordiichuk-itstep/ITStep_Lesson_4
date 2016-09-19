#include <cstdio>

int main(int argc, char** argv) {
  const char* const dictionary[] = {"mathematics", "physics", "biology", "psychology", "geometry", "geography", 
            "geology", "bioinformatics", "science", "scifi", "pharmacology", "musics", "analysis", 
            "policy", "geopolicy", "politology", "demonology", "demonstations", "bioengineering", 
            "modeling", "algebra", "literature", "liberation", "listing", "society", "scene", "lighting"};
  size_t SIZE = sizeof(dictionary) / sizeof(dictionary[0]);
  
  char key_search[32];
  printf("enter key search: ");
  scanf("%s", key_search);
  
  const char* delimiter = "";
  for (size_t i = 0; i < SIZE; ++i) {
    if (key_search[0] == dictionary[i][0]) {
      printf("%s%s", delimiter, dictionary[i]);
      delimiter = ", ";
    }
  }
  return 0;
}