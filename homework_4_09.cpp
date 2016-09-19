#include <cstdio>

int main(int argc, char** argv){
  size_t index = 0;
  size_t word = 0;
  const char* text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam eleifend condimentum magna imperdiet tristique. Pellentesque fringilla maximus mi vitae ullamcorper. Fusce mattis neque vel nisi fringilla, vel aliquet libero sagittis. Nullam fringilla at mi at accumsan. Suspendisse ullamcorper auctor enim, eu malesuada felis ornare eu. Morbi sodales nunc eget lacus sollicitudin semper. Donec tristique consequat tellus, ut porttitor felis maximus eget. Fusce consectetur iaculis pharetra. Donec congue volutpat arcu, eget sodales sapien tristique quis. Nullam ut posuere risus, sed pharetra lorem. Cras varius, est eu pulvinar scelerisque, ipsum nisi bibendum sapien, in scelerisque velit risus eget felis. Nam nec porttitor erat. Suspendisse dictum sit amet magna finibus lobortis. Phasellus non sem mollis, ultrices odio non, volutpat ligula. Aenean mollis eros ex, vitae lobortis quam gravida sed. ";
  while (text[index] != '\0') {
    if (text[index] == ' ') {
      ++word;
    }
    ++index;
  }
  printf("In text \"%s\" - %i words", text, word);
  return 0;
}