// Modification timestamp: 2023-08-14 13:48:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980424-1.c
int i, a[99];

void f (int one)
{
  if (one != 1)
    abort ();
}

void
g ()
{
  f (a[i & 0x3f]);
}

int
main ()
{
  a[0] = 1;
  i = 0x40;
  g ();
  exit (0);
}
