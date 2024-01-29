// Modification timestamp: 2023-08-14 14:34:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/mayalias-3.c

#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((__may_alias__)) {
  short x;
} test;

test *p;

int g(test *a) {
  p = a;
}

int f() {
  test s = {1};
  g(&s);
  int a = 10;
  *p = s;
  return a;
}

int main() {
  if (f() == 10)
    abort();
  return 0;
}
