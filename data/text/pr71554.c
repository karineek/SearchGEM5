// Modification timestamp: 2023-08-14 15:51:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71554.c
/* PR target/71554 */

int v;

__attribute__ ((noinline, noclone)) void
bar (void)
{
  v++;
}

__attribute__ ((noinline, noclone))
void
foo (unsigned int x)
{
  signed int y = ((-__INT_MAX__ - 1) / 2);
  signed int r;
  if (__builtin_mul_overflow (x, y, &r))
    bar ();
}

int
main ()
{
  foo (2);
  if (v)
    __builtin_abort ();
  return 0;
}
