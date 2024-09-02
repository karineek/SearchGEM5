// Modification timestamp: 2023-08-14 11:54:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001112-1.c
int main ()
{
  long long i = 1;

  i = i * 2 + 1;

  if (i != 3)
    abort ();
  exit (0);
}
