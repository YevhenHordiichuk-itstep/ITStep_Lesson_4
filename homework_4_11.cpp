#include <cstdio>
#include <cstring>

int main(int argc, char** argv) {
  const char* dictionary[] = {"mathematics", "physics", "biology", "psychology", "geometry", "geography", 
            "geology", "bioinformatics", "science", "scifi", "pharmacology", "musics", "analysis", 
            "policy", "geopolicy", "politology", "demonology", "demonstations", "bioengineering", 
            "modeling", "algebra", "literature", "liberation", "listing", "society", "scene", "lighting"};
  size_t SIZE = sizeof(dictionary) / sizeof(dictionary[0]);
  char str[32];
  printf("Enter key search: ");
  scanf("%s", str);
  bool search = false;
  for (size_t i = 0; i < SIZE; ++i) {
    if (strcmp(str, dictionary[i]) != 0) {
      search = true;
      break;
    }
  }
  
  if (search) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}