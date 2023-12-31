// Modification timestamp: 2023-08-14 12:49:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031003-1.c
/* PR optimization/9325  */

#include <limits.h>

extern void abort (void);

int f1()
{
  return (int)2147483648.0f;
}

int f2()
{
  return (int)(float)(2147483647);
}

int main()
{
#if INT_MAX == 2147483647
  if (f1() != 2147483647)
    abort ();
#ifdef __SPU__
  /* SPU float rounds towards zero.  */
  if (f2() != 0x7fffff80)
    abort ();
#else
  if (f2() != 2147483647)
    abort ();
#endif
#endif
  return 0;
}
