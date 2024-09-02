// Modification timestamp: 2023-08-14 12:59:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041114-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void abort (void);

volatile int v;

void foo (int var)
{
  if (!(var <= 0 || ((unsigned long) (unsigned) (var - 1) < UINT_MAX)))
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int v = atoi(argv[1]);
  foo(v);
  return 0;
}

#ifndef __OPTIMIZE__
void abort (void) {
  exit(1);
}
#endif
