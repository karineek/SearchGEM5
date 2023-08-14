// Modification timestamp: 2023-08-14 15:22:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52286.c
/* PR tree-optimization/52286 */

extern void abort (void);

int
main ()
{
#if __SIZEOF_INT__ > 2
  int a, b;
  asm ("" : "=r" (a) : "0" (0));
  b = (~a | 1) & -2038094497;
#else
  long a, b;
  asm ("" : "=r" (a) : "0" (0));
  b = (~a | 1) & -2038094497L;
#endif
  if (b >= 0)
    abort ();
  return 0;
}
