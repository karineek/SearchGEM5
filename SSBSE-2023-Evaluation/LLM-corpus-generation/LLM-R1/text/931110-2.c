// Modification timestamp: 2023-08-14 13:39:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931110-2.c
main ()
{
  static int a[] = {3, 4};
  register int *b;
  int c;

  b = a;
  c = *b++ % 8;
  if (c != 3)
    abort ();
  exit (0);
}
