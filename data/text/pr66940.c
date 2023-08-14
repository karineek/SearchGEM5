// Modification timestamp: 2023-08-14 15:45:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr66940.c
long long __attribute__ ((noinline, noclone))
foo (long long ival)
{
 if (ival <= 0)
    return -0x7fffffffffffffffL - 1;

 return 0x7fffffffffffffffL;
}

int
main (void)
{
  if (foo (-1) != (-0x7fffffffffffffffL - 1))
    __builtin_abort ();

  if (foo (1) != 0x7fffffffffffffffL)
    __builtin_abort ();

  return 0;
}
