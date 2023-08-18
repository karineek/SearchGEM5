// Modification timestamp: 2023-08-14 14:32:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-7.c

#include <stdio.h>
#include <stdlib.h>

void foo(unsigned int n)
{
  int i, j = -1;

  for (i = 0; i < 10 && j < 0; i++) {
    if ((1UL << i) == n)
      j = i;
  }

  if (j < 0)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <n>\n", argv[0]);
    return 1;
  }

  unsigned int n = atoi(argv[1]);
  foo(n);

  exit(0);
}
