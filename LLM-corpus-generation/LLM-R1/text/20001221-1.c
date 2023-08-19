// Modification timestamp: 2023-08-14 11:55:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001221-1.c
int main ()
{
  unsigned long long a;
  if (! (a = 0xfedcba9876543210ULL))
    abort ();
  exit (0);
}
