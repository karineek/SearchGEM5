// Modification timestamp: 2023-08-14 14:49:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr24851.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

int main(int argc, char *argv[]) {
  int a[10], *p, *q;
  q = &a[1];
  p = &q[-1];
  if (p >= &a[9])
    abort();
  return 0;
}
