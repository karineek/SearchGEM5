// Modification timestamp: 2023-08-14 13:45:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960321-1.c
char a[10] = "deadbeef";

char
acc_a (long i)
{
  return a[i-2000000000L];
}

main ()
{
  if (acc_a (2000000000L) != 'd')
    abort ();
  exit (0);
}
