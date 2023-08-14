// Modification timestamp: 2023-08-14 15:27:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56962.c
/* PR tree-optimization/56962 */

extern void abort (void);
long long v[144];

__attribute__((noinline, noclone)) void
bar (long long *x)
{
  if (x != &v[29])
    abort ();
}

__attribute__((noinline, noclone)) void
foo (long long *x, long y, long z)
{
  long long a, b, c;
  a = x[z * 4 + y * 3];
  b = x[z * 5 + y * 3];
  c = x[z * 5 + y * 4];
  x[y * 4] = a;
  bar (&x[z * 5 + y]);
  x[z * 5 + y * 5] = b + c;
}

int
main ()
{
  foo (v, 24, 1);
  return 0;
}
