// Modification timestamp: 2023-08-14 12:51:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040208-1.c
int main ()
{
  long double x;

  x = 0x1.0p-500L;
  x *= 0x1.0p-522L;
  if (x != 0x1.0p-1022L)
    abort ();
  exit (0);
}
