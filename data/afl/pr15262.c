// Modification timestamp: 2023-08-14 14:42:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr15262.c

#include <stdio.h>
#include <stdlib.h>

struct A {
  int t;
  int i;
};

void bar(float *p) {
  *p = 5.2;
}

int foo(struct A *locp, int i, int str) {
  float f, g, *p;
  int T355;
  int *T356;

  p = i ? &g : &f;
  bar(p);
  if (*p > 0.0)
    str = 1;

  T355 = locp->i;
  T356 = &locp->i;
  *T356 = str;
  T355 = locp->i;

  return T355;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct A loc;
  int str;

  loc.i = atoi(argv[1]);
  str = foo(&loc, 10, 3);
  if (str != 1)
    abort();
  return 0;
}

