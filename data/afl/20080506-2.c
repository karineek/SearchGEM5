// Modification timestamp: 2023-08-14 13:13:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080506-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

void __attribute__((noinline)) foo(int **__restrict p, int **__restrict q) {
  *p[0] = 1;
  *q[0] = 2;
  if (*p[0] != 2)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int *p1 = &a, *p2 = &a;
  foo(&p1, &p2);
  return 0;
}
