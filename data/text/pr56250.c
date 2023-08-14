// Modification timestamp: 2023-08-14 15:26:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56250.c
/* PR tree-optimization/56250 */

extern void abort (void);

int
main ()
{
  unsigned int x = 2;
  unsigned int y = (0U - x / 2) / 2;
  if (-1U / x != y)
    abort ();
  return 0;
}
