// Modification timestamp: 2023-08-14 15:19:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49768.c
/* PR tree-optimization/49768 */

extern void abort (void);

int
main ()
{
  static struct { unsigned int : 1; unsigned int s : 1; } s = { .s = 1 };
  if (s.s != 1)
    abort ();
  return 0;
}
