// Modification timestamp: 2023-08-14 15:36:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59221.c
#include <stdio.h>
#include <stdlib.h>

int a = 1, b, d;
short e;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  b = atoi(argv[1]);

  for (; b; b++)
    ;
  short f = a;
  int g = 15;
  e = f ? f : 1 << g;
  int h = e;
  d = h == 83647 ? 0 : h;
  if (d != 1)
    __builtin_abort ();
  return 0;
}
