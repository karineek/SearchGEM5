// Modification timestamp: 2023-08-14 13:31:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921123-1.c
f(short *p)
{
  short x = *p;
  return (--x < 0);
}

main()
{
  short x = -10;
  if (!f(&x))
    abort();
  exit(0);
}
