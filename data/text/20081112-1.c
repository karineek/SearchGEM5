// Modification timestamp: 2023-08-14 13:15:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20081112-1.c
#include <limits.h>

extern void abort (void);

static __attribute__((noinline)) void foo (int a)
{
  int b = (a - 1) + INT_MIN;

  if (b != INT_MIN)
    abort ();
}

int main (void)
{
  foo (1);
  return 0;
}
