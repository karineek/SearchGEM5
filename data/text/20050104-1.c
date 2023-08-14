// Modification timestamp: 2023-08-14 13:00:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050104-1.c
/* PR tree-optimization/19060 */

void abort (void);

static
long long min ()
{
  return -__LONG_LONG_MAX__ - 1;
}

void
foo (long long j)
{
  if (j > 10 || j < min ())
    abort ();
}

int
main (void)
{
  foo (10);
  return 0;
}
