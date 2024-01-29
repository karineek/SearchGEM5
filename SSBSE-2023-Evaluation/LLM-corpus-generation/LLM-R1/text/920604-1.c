// Modification timestamp: 2023-08-14 13:27:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920604-1.c
long long
mod (a, b)
     long long a, b;
{
  return a % b;
}

int
main ()
{
  mod (1LL, 2LL);
  exit (0);
}
