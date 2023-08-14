// Modification timestamp: 2023-08-14 13:32:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921202-2.c
int
f(long long x)
{
  x >>= 8;
  return x & 0xff;
}

main()
{
  if (f(0x0123456789ABCDEFLL) != 0xCD)
    abort();
  exit (0);
}
