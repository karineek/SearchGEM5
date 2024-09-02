// Modification timestamp: 2023-08-14 14:47:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr23047.c
/* { dg-options "-fwrapv" } */
#include <limits.h>
extern void abort ();
extern void exit (int);
void f(int i)
{
  i = i > 0 ? i : -i;
  if (i<0)
    return;
  abort ();
}

int main(int argc, char *argv[])
{
  f(INT_MIN);
  exit (0);
}
