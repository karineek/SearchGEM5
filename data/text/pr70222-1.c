// Modification timestamp: 2023-08-14 15:49:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70222-1.c
/* PR rtl-optimization/70222 */

int a = 1;
unsigned int b = 2;
int c = 0;
int d = 0;

void
foo ()
{
  int e = ((-(c >= c)) < b) > ((int) (-1ULL >> ((a / a) * 15)));
  d = -e;
}

__attribute__((noinline, noclone)) void
bar (int x)
{
  if (x != -1)
    __builtin_abort ();
}

int
main ()
{
#if __CHAR_BIT__ == 8 && __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8
  foo ();
  bar (d);
#endif
  return 0;
}
