// Modification timestamp: 2023-08-14 13:57:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991030-1.c
double x = 0x1.fp1;
int main()
{
  if (x !=  3.875)
    abort ();
  exit (0);
}
