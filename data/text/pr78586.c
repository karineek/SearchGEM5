// Modification timestamp: 2023-08-14 15:52:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78586.c
/* PR tree-optimization/78586 */

void
foo (unsigned long x)
{
  char a[30];
  unsigned long b = __builtin_sprintf (a, "%lu", x);
  if (b != 4)
    __builtin_abort ();
}

int
main ()
{
  foo (1000);
  return 0;
}
