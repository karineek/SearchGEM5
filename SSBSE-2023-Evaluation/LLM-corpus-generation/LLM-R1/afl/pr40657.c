// Modification timestamp: 2023-08-14 15:06:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40657.c

#include <stdio.h>
#include <stdlib.h>

long long v = 0x123456789abc;

__attribute__((noinline)) void bar(int *x)
{
  asm volatile("" : "=m"(x)::);
}

__attribute__((noinline)) long long foo()
{
  int x;
  bar(&x);
  return v;
}

int main()
{
  if (foo() != v)
    abort();
  exit(0);
}
