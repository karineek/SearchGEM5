// Modification timestamp: 2023-08-14 15:27:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57281.c
/* PR rtl-optimization/57281 */

int a = 1, b, d, *e = &d;
long long c, *g = &c;
volatile long long f;

int
foo (int h)
{
  int j = *g = b;
  return h == 0 ? j : 0;
}

int
main ()
{
  int h = a;
  for (; b != -20; b--)
    {
      (int) f;
      *e = 0;
      *e = foo (h);
    }
  return 0;
}
