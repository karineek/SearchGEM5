// Modification timestamp: 2023-08-14 15:39:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61682.c

#include <stdio.h>
#include <stdlib.h>

int a, b;
static int *c = &b;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int *d = &a;
  for (a = atoi(argv[1]); a < 12; a++)
    *c |= *d / 9;

  if (b != 1)
    __builtin_abort();

  return 0;
}
