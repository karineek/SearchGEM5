// Modification timestamp: 2023-08-14 14:30:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-11.c

#include <stdio.h>
#include <stdlib.h>

static int a[199];

static void foo() {
  int i;
  for (i = 198; i >= 0; i--)
    a[i] = i;
}

int main() {
  foo();
  for (int i = 0; i < 199; i++)
    if (a[i] != i)
      abort();
  return 0;
}
