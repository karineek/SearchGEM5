// Modification timestamp: 2023-08-14 14:30:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-2d.c

#include <stdio.h>
#include <stdlib.h>

int a[2];

void f(int b) {
  unsigned int i;
  int *p;
  for (p = &a[b], i = b; --i < ~0; )
    *--p = i * 3 + (int)a;
}

int main(int argc, char *argv[]) {
  a[0] = a[1] = 0;
  f(2);
  if (a[0] != (int)a || a[1] != (int)a + 3)
    abort();
  exit(0);
}
