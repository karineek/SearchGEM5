// Modification timestamp: 2023-08-14 11:59:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010604-1.c
#include <stdbool.h>

int f (int a, int b, int c, _Bool d, _Bool e, _Bool f, char g)
{
  if (g != 1 || d != true || e != true || f != true) abort ();
  return a + b + c;
}

int main (void)
{
  if (f (1, 2, -3, true, true, true, '\001'))
    abort ();
  exit (0);
}
