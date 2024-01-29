// Modification timestamp: 2023-08-14 12:46:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030606-1.c

int * foo (int *x, int b)
{

  *(x++) = 55;
  if (b)
    *(x++) = b;

  return x;
}

main()
{
  int a[5];

  memset (a, 1, sizeof (a));

  if (foo(a, 0) - a != 1 || a[0] != 55 || a[1] != a[4])
    abort();

  memset (a, 1, sizeof (a));

  if (foo(a, 2) - a != 2 || a[0] != 55 || a[1] != 2)
    abort();

  exit (0);
}
