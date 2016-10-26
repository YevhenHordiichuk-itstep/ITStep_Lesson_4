//homework_4_02       Queue

#include <cstdio>
#include <cstring>
#include <cstdlib>

int leftstack[10];
const size_t SIZE = 10;
int rightstack[10];
int head = 0;
int tail = 0;

void enqueue(int element) {
  if (tail >= SIZE) {
    printf("Queue Overflow!\n");
    return;
  }
  leftstack[tail++] = element;
}

int popLeftStack() {
  --tail;
  return leftstack[tail];
}

void popRightStack() {
  --head;
}

void pushRightStack(int element) {
  rightstack[head++] = element;
}

void dequeue() {
  if (head == 0) {
    if (tail == 0) {
      printf("Queue Underflow!\n");
      return;
    }
    while (tail != 0) {
      pushRightStack(popLeftStack());
    }
  }
  popRightStack();
}

int tailPrint() {
  if (tail == 0) {
    if (head == 0) {
      printf("Queue Underflow!-\n");
      return NULL;
    }
    return rightstack[0];
  }
  if (tail >= 10) {
    printf("Queue Overflow!\n");
    return NULL;
  }
  return leftstack[tail - 1];
}

int headPrint() {
  if (head == 0) {
    if (tail == 0) {
      printf("Queue Underflow!\n");
      return NULL;
    }
    return leftstack[0];
  }
  if (head >= 10) {
    printf("Queue Overflow!\n");
    return NULL;
  }
  return rightstack[head - 1];
}

void print() {
  size_t i = tail;
  while (i != 0) {
    printf("_%i", leftstack[i - 1]);
    --i;
  }
  
  i = 0;
  while (i != head) {
    printf("_%i", rightstack[i]);
    ++i;
  }
  
  printf("\n");
}

enum Command {
  HEAD = 1,
  TAIL = 2,
  ENQUEUE = 3,
  DEQUEUE = 4,
  PRINT = 5,
  EXIT = 6,
  UNKNOWN = -1
};

int main(int argc, char** argv) {
  while(true) {
    char array[10];
    char* str = array;
    scanf("%s", str);
    
    Command c;
    if (strcmp(str, "head") == 0) {
      c = HEAD;
    } else if (strcmp(str, "tail") == 0) {
      c = TAIL;
    } else if (strcmp(str, "enq") == 0) {
      c = ENQUEUE;
    } else if (strcmp(str, "deq") == 0) {
      c = DEQUEUE;
    } else if (strcmp(str, "print") == 0) {
      c = PRINT;
    } else if (strcmp(str, "exit") == 0) {
      c = EXIT;
    } else {
      c = UNKNOWN;
    }
    
    switch (c) {
      case HEAD:
        printf("%i\n", headPrint());
        break;
      case TAIL:
        printf("%i\n", tailPrint());
        break;
      case ENQUEUE:
        int value;
        value = -10 + rand() % 20;
        printf("\t\t\t\t\t\t\t%i\n", value);
        //scanf("%i", &value);
        enqueue(value);
        print();
        break;
      case DEQUEUE:
        dequeue();
        print();
        break;
      case PRINT:
        print();
        break;
      case EXIT:
        return 0;
      case UNKNOWN:
      default:
        printf("Wrong Command!\n");
        break;
    }
  }
  
  return 0;
}
