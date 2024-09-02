// Modification timestamp: 2023-08-14 15:30:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58385.c
/* PR tree-optimization/58385 */

extern void abort (void);

int a, b = 1;

int
foo ()
{
  b = 0;
  return 0;
}

int
main ()
{
  ((0 || a) & foo () >= 0) <= 1 && 1;
  if (b)
    abort ();
  return 0;
}
