// Modification timestamp: 2023-08-14 13:17:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20090814-1.c

#include <stdio.h>
#include <stdlib.h>

int bar(int *a) {
  return *a;
}

int i;

int foo(int (*a)[2]) {
  return bar(&(*a)[i]);
}

extern void abort(void);

int main(int argc, char *argv[]) {
  int a[2];
  a[0] = -1;
  a[1] = 42;
  i = 1;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int result = foo(&a);

  int expected = atoi(argv[1]);
  if (result != expected) {
    abort();
  }

  return 0;
}
