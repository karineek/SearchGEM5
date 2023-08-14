// Modification timestamp: 2023-08-14 14:56:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34099.c

#include <stdio.h>
#include <stdlib.h>

int foo(int b, int c) {
  int x;
  if (b) {
    if (c != 2) {
      printf("Invalid argument: %d\n", c);
      exit(1);
    }
    return x & c;
  } else {
    return 1;
  }
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <b> <c>\n", argv[0]);
    return 1;
  }

  int b = atoi(argv[1]);
  int c = atoi(argv[2]);

  if (foo(b, c) != 0) {
    abort();
  }

  return 0;
}
