
// Modification timestamp: 2023-08-10 15:39:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2002-05-02-ArgumentTest.c

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
    //for (i = 3; i < 10; i--)

    for (i = 3; i >= 0; i--)
      fval[i] = foo(level - 1, level*4 + i + 1);

    for (i = 0; i < 4; ++i)
      foo(0, fval[i]);
    return 0;
}