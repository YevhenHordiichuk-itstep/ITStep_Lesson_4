#include <cstdio>
#include <cstring>

int stack[10];
int buffer[10];
int head = 0;

void getMax() {
  if (head == 0) {
    printf("Stack Underflow!\n");
  } else {
    printf("%i\n", buffer[head - 1]);
  }
}

int top() {
  if (head == 0) {
    printf("Stack Underflow!\n");
    return 0;
  }
  if (head >= 10) {
    printf("Stack Overflow!\n");
    return 0;
  }
  return stack[head - 1];
}

void push(int element, int max) {
  if (head >= 10) {
    printf("Stack Overflow!\n");
  } else {
    stack[head] = element;
    buffer[head] = max;
    ++head;
  }
}

void pop(int* pps) {
  if (head == 0) {
    printf("Stack Underflow!\n");
  } else {
    --head;
    if (head != 0) {
      (*pps) = buffer[head - 1];
    } 
  }
}

void print() {
  for (int i = 0; i < head; ++i) {
    printf("%i_", stack[i]);
  }
  printf("\n");
}


enum Command {
  TOP = 1,
  PUSH = 2,
  POP = 3,
  PRINT = 4,
  EXIT = 5,
  GETMAX = 6,
  UNKNOWN = -1
};


int main(int argc, char** argv) {
  while(true) {
    int max;
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
    } else if (strcmp(str, "getmax") == 0) {
      c = GETMAX;
    } else {
      c = UNKNOWN;
    }

    switch (c) {
      case TOP:
        printf("%i\n", top());
        break;
      case PUSH:
        int value;
        scanf("%i", &value);
        if (head == 0 || value > max) {
          max = value;
        } 
        push(value, max);
        break;
      case POP:
        pop(&max);
        break;
      case PRINT:
        print();
        break;
      case EXIT:
        return 0;
      case GETMAX:
        getMax();
        break;
      case UNKNOWN:
      default:
        printf("Wrong Command!\n");
        break;
    }
  }   
  return 0;
}