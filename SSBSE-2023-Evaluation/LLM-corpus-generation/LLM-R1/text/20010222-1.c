// Modification timestamp: 2023-08-14 11:57:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010222-1.c
int a[2] = { 18, 6 };

int main ()
{
  int b = (-3 * a[0] -3 * a[1]) / 12;
  if (b != -6)
    abort ();
  exit (0);
}
