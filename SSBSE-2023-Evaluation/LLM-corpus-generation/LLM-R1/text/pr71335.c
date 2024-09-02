// Modification timestamp: 2023-08-14 15:50:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71335.c
int a;
int
main ()
{
  int b = 0;
  while (a < 0 || b)
    {
      b = 0;
      for (; b < 9; b++)
	;
    }
  exit (0);
}
