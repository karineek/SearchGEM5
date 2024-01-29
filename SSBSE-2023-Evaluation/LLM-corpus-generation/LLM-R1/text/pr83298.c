// Modification timestamp: 2023-08-14 15:59:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr83298.c

int a, b, c = 1;

int main ()
{
  for (; b < 1; b++)
    ;
  if (!(c * (a < 1)))
    __builtin_abort ();
  return 0;
}
