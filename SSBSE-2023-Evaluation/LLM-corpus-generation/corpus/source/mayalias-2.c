// Modification timestamp: 2023-08-14 14:34:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/mayalias-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((__may_alias__)) {
  short x;
} test;

int f(int a) {
  test *p = (test *)&a;
  p->x = 1;
  return a;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  if (f(a) == a) {
    printf("Error: f() did not modify the value of a\n");
    return 1;
  }

  return 0;
}
