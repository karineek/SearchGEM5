// Modification timestamp: 2023-08-14 17:27:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/TestLoop.c

#include <stdio.h>
#include <stdlib.h>

int foo(int i, int j) {
  printf("%d\n", j);
  return j;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <level>\n", argv[0]);
    return 1;
  }

  int level = atoi(argv[1]);
  int i;
  int fval[4];

  for (i = 3; i >= 0; i--)
    fval[i] = foo(level - 1, level*4 + i + 1);

  for (i = 0; i < 4; ++i)
    foo(0, fval[i]);

  return 0;
}
