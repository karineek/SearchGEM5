// Modification timestamp: 2023-08-14 11:52:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001009-2.c

#include <stdio.h>
#include <stdlib.h>

int b = 1;

int foo(int a, int c) {
  for (; b; b--) {
    c = 1;
    asm(""::"r"(c));
    c = (signed char)a;
  }
  if (c != -1)
    abort();
  return c;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int c;

  c = foo(a, 0);
  return 0;
}
