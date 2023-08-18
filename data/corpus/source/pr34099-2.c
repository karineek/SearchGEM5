// Modification timestamp: 2023-08-14 14:56:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34099-2.c

#include <stdio.h>
#include <stdlib.h>

int test1(int b, int c) {
  char x;
  if (b) {
    if (c == 0) {
      printf("Division by zero is undefined.\n");
      exit(1);
    }
    return x / c;
  } else {
    return 1;
  }
}

int test2(int b, int c) {
  int x;
  if (b) {
    return x * c;
  } else {
    return 1;
  }
}

int test3(int b, int c) {
  int x;
  if (b) {
    if (c == 0) {
      printf("Division by zero is undefined.\n");
      exit(1);
    }
    return x % c;
  } else {
    return 1;
  }
}

int test4(int b, int c) {
  char x;
  if (b) {
    return x == c;
  } else {
    return 1;
  }
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int b = atoi(argv[1]);
  int c = atoi(argv[2]);

  if (test1(b, c) != 0)
    abort();
  if (test2(b, c) != 0)
    abort();
  if (test3(b, c) != 0)
    abort();
  if (test4(b, c) != 0)
    abort();

  return 0;
}
