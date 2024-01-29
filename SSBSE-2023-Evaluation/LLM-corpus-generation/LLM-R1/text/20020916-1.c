// Modification timestamp: 2023-08-14 12:36:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020916-1.c
/* Distilled from try_pre_increment in flow.c.  If-conversion inserted
   new instructions at the wrong place on ppc.  */

int foo(int a)
{
  int x;
  x = 0;
  if (a > 0) x = 1;
  if (a < 0) x = 1;
  return x;
}

int main()
{
  if (foo(1) != 1)
    abort();
  return 0;
}
