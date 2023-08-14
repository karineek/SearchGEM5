// Modification timestamp: 2023-08-14 13:32:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921218-2.c
f()
{
  long l2;
  unsigned short us;
  unsigned long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}

main()
{
  if (f()!=(unsigned short)-1)
    abort();
  exit(0);
}
