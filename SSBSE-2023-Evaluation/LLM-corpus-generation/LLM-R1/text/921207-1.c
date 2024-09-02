// Modification timestamp: 2023-08-14 13:32:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921207-1.c
f()
{
  unsigned b = 0;

  if (b > ~0U)
    b = ~0U;

  return b;
}
main()
{
  if (f()!=0)
    abort();
  exit (0);
}
