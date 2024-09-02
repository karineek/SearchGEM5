// Modification timestamp: 2023-08-14 15:03:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr39120.c

#include <stdio.h>
#include <stdlib.h>

struct X { int *p; } x;

struct X __attribute__((noinline)) foo(int *p) {
  struct X x;
  x.p = p;
  return x;
}

void __attribute__((noinline)) bar() {
  *x.p = 1;
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  x = foo(&i);
  bar();
  if (i != 1)
    abort();
  return 0;
}
