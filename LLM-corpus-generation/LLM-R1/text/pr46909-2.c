// Modification timestamp: 2023-08-14 15:15:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46909-2.c
/* PR tree-optimization/46909 */

extern void abort (void);

int
__attribute__((noinline))
foo (int x)
{
  if ((x != 0 && x != 13) || x == 5 || x == 20)
    return 1;
  return -1;
}

int
main (void)
{
  int i;
  for (i = -10; i < 30; i++)
    if (foo (i) != 1 - 2 * (i == 0) - 2 * (i == 13))
      abort ();
  return 0;
}
