// Modification timestamp: 2023-08-14 15:39:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61725.c
/* PR tree-optimization/61725 */

int
main ()
{
  int x;
  for (x = -128; x <= 128; x++)
    {
      int a = __builtin_ffs (x);
      if (x == 0 && a != 0)
        __builtin_abort ();
    }
  return 0;
}
