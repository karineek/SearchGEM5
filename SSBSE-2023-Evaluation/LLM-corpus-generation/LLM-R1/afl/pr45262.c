// Modification timestamp: 2023-08-14 15:14:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr45262.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(unsigned int x) {
  return ((int)x < 0) || ((int)(-x) < 0);
}

int bar(unsigned int x) {
  return x >> 31 || (-x) >> 31;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int x = atoi(argv[1]);

  if (foo(x) != 1)
    abort();
  if (foo(0) != 0)
    abort();
  if (foo(-1) != 1)
    abort();
  if (bar(x) != 1)
    abort();
  if (bar(0) != 0)
    abort();
  if (bar(-1) != 1)
    abort();

  return 0;
}
