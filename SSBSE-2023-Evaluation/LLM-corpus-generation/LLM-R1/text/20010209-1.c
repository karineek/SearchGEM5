// Modification timestamp: 2023-08-14 11:57:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010209-1.c
/* { dg-require-effective-target alloca } */
int b;
int foo (void)
{
  int x[b];
  int bar (int t[b])
  {
    int i;
    for (i = 0; i < b; i++)
      t[i] = i + (i > 0 ? t[i-1] : 0);
    return t[b-1];
  }
  return bar (x);
}

int main ()
{
  b = 6;
  if (foo () != 15)
    abort ();
  exit (0);
}
