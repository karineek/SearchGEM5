// Modification timestamp: 2023-08-14 15:41:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64260.c

#include <stdio.h>
#include <stdlib.h>

int a, b;

void foo(char p, int* pa, int* pb) {
  int t = 0;
  for (; *pb < 1; (*pb)++) {
    int* s = pa;
    if (--t)
      *s &= p;
    *s &= 1;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = 0;

  foo(0, &a, &b);

  if (a != 0)
    __builtin_abort();

  return 0;
}
