// Modification timestamp: 2023-08-14 15:44:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr66187.c

#include <stdio.h>
#include <stdlib.h>

int a = 1, e = -1;
short b, f;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  f = atoi(argv[1]);
  int g = b < 0 ? 0 : f + b;
  if ((g & -4) < 0)
    a = 0;
  if (a)
    __builtin_abort ();
  return 0;
}
