// Modification timestamp: 2023-08-14 12:10:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020225-2.c
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0;
  a.i = 1;
  return x >> a.i;
}

int main(void)
{
  if (test (5) != 2)
    abort ();
  exit (0);
}
