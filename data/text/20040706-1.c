// Modification timestamp: 2023-08-14 12:56:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040706-1.c
int main ()
{
  int i;
  for (i = 0; i < 10; i++)
    continue;
  if (i < 10)
    abort ();
  exit (0);
}
