// Modification timestamp: 2023-08-14 15:25:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr54471.c
/* PR tree-optimization/54471 */

#ifdef __SIZEOF_INT128__
#define T __int128
#else
#define T long long
#endif

extern void abort (void);

__attribute__ ((noinline))
unsigned T
foo (T ixi, unsigned ctr)
{
  unsigned T irslt = 1;
  T ix = ixi;

  for (; ctr; ctr--)
    {
      irslt *= ix;
      ix *= ix;
    }

  if (irslt != 14348907)
    abort ();
  return irslt;
}

int
main ()
{
  unsigned T res;

  res = foo (3, 4);
  return 0;
}
