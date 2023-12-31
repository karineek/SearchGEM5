// Modification timestamp: 2023-08-14 14:30:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-14.c
int a3[3];

void f(int *a)
{
  int i;

  for (i=3; --i;)
    a[i] = 42 / i;
}

int
main ()
{
  f(a3);

  if (a3[1] != 42 || a3[2] != 21)
    abort ();

  exit (0);
}
