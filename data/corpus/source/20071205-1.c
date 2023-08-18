// Modification timestamp: 2023-08-14 13:11:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071205-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(int x) {
  return ((x << 8) & 65535) | 255;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);

  if (foo(arg1) != arg2) {
    abort();
  }

  return 0;
}

