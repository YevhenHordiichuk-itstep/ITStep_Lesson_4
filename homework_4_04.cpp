#include <cstdio>
#include <cstring>

int stack[10];
int head = 0;
int openmode = 0;
int closemode = 0;

int truBrace(int openmode, int closemode) {
  if (head == 0) {
    return printf("Stack Underflow!\n");
  } 
  if (head >= 10) {
  return printf("Stack Overflow!\n");
  }
  if (openmode == 0 && closemode == 0) {
    return printf("YES\n");
  } else {
    return printf("NO\n");
  }
  }

int top() {
  if (head == 0) {
    return printf("Stack Underflow!\n");
  }
  if (head >= 10) {
    return printf("Stack Overflow!\n");
  }
  return printf("%c\n", stack[head - 1]);
}

void push(char element) {
  if (head >= 10) {
    printf("Stack Overflow!\n");
  } else {
    stack[head++] = element;
    
    if (closemode == 0) {
      if (stack[head - 1] == '(') {
        ++openmode;
        printf("%i %i", openmode, closemode);
        return;
      } else if (stack[head - 1] == ')' && openmode >= 1) {
        --openmode;
        printf("%i %i", openmode, closemode);
        return;
      }
    }
    if (stack[head - 1] == ')') {
      --closemode;
      printf("%i %i", openmode, closemode);
    }
  }
}

void pop() {
  if (head == 0) {
    printf("Stack Underflow!\n");
  } else {
    if (closemode == 0) {
      if (stack[head - 1] == '(') {
        --openmode;
      } else if (stack[head - 1] == ')') {
        ++openmode;
      }
    } else {
      if (stack[head - 1] == ')') {
        ++closemode;
      }
    }
    --head;
  }
}

void print() {
  for (int i = 0; i < head; ++i) {
    printf("%c", stack[i]);
  }
  printf("\n");
}

enum Command {
  TOP = 1,
  PUSH = 2,
  POP = 3,
  PRINT = 4,
  EXIT = 5,
  TRUEBRACE = 6,
  UNKNOWN = -1
};

int main(int argc, char** argv) {
  while(true) {
    char array[10];
    char* str = array;
    scanf("%s", str);
    
    Command c;
    if (strcmp(str, "top") == 0) {
      c = TOP;
    } else if (strcmp(str, "push") == 0) {
      c = PUSH;
    } else if (strcmp(str, "pop") == 0) {
      c = POP;
    } else if (strcmp(str, "print") == 0) {
      c = PRINT;
    } else if (strcmp(str, "exit") == 0) {
      c = EXIT;
    } else if (strcmp (str, "truebrace") == 0) {
      c = TRUEBRACE;
    } else {
      c = UNKNOWN;
    }
    
    switch (c) {
      case TOP:
        top();
        break;
      case PUSH:
        char value;
        scanf("%s\n", &value);
        push(value); 
        break;
      case POP:
        pop();
        break;
      case PRINT:
        printf("%i %i\n", openmode, closemode);
        print();
        break;
      case EXIT:
        return 0;
      case TRUEBRACE:
        trueBrace(openmode, closemode);
        break;
      case UNKNOWN:
      default:
        printf("Wrong Command!\n");
        break;
    }
  }
  return 0;
}
