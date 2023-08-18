// Modification timestamp: 2023-08-14 13:46:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960512-1.c

#include <stdio.h>
#include <stdlib.h>

double f(int a[])
{
  __complex__ double c;

  a[9] = 0;
  c = a[9];
  return c;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  __complex__ double c;

  int a[40];

  c = f(a);

  if (c)
    abort();

  exit(0);
}
