// Modification timestamp: 2023-08-14 14:45:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22061-4.c
/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
void
bar (int N)
{
  void foo (int a[2][N++]) {}
  int a[2][N];
  foo (a);
  int b[2][N];
  foo (b);
  if (sizeof (a) != sizeof (int) * 2 * 1)
    abort ();
  if (sizeof (b) != sizeof (int) * 2 * 2)
    abort ();
  if (N != 3)
    abort ();
}

int
main (void)
{
  bar (1);
  exit (0);
}
