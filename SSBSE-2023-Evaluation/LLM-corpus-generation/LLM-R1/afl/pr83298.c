// Modification timestamp: 2023-08-14 15:59:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr83298.c

#include <stdio.h>
#include <stdlib.h>

int a, b, c = 1;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <a> <b> <c>\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);

  for (; b < 1; b++)
    ;
  if (!(c * (a < 1)))
    __builtin_abort ();
  return 0;
}
