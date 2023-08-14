// Modification timestamp: 2023-08-14 12:07:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011217-1.c
int
main()
{
  double x = 1.0;
  double y = 2.0;

  if ((y > x--) != 1)
    abort ();
  exit (0);
}
