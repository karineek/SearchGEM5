// Modification timestamp: 2023-08-14 12:38:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021119-1.c
/* PR 8639.  */

extern void abort(void);

int foo (int i)
{
  int r;
  r = (80 - 4 * i) / 20;
  return r;
}

int main ()
{
  if (foo (1) != 3)
    abort ();
  return 0;
}
