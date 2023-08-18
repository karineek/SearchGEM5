// Modification timestamp: 2023-08-14 14:31:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-2e.c

#include <stdio.h>
#include <stdlib.h>

void f(int *p, int **q) {
  int i;
  for (i = 0; i < 40; i++) {
    *q++ = &p[i];
  }
}

int main(int argc, char *argv[]) {
  void *p;
  int *q[40];
  __SIZE_TYPE__ start;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int value = atoi(argv[1]);

  if (sizeof(start) == sizeof(int))
    start = (__SIZE_TYPE__)value;
  else if (sizeof(start) == sizeof(long))
    start = (__SIZE_TYPE__)value;
  else if (sizeof(start) == sizeof(long long))
    start = (__SIZE_TYPE__)value;
  else
    return 0;

  start &= -32;

  p = (void *)start;

  q[39] = 0;
  f((int *)p, q);
  if (q[39] != (int *)p + 39)
    abort();

  return 0;
}
