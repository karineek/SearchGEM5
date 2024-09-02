// Modification timestamp: 2023-08-14 12:58:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040820-1.c
/* PR rtl-optimization/17099 */

extern void exit (int);
extern void abort (void);

void
check (int a)
{
  if (a != 1)
    abort ();
}

void
test (int a, int b)
{
  check ((a ? 1 : 0) | (b ? 2 : 0));
}

int
main (void)
{
  test (1, 0);
  exit (0);
}
