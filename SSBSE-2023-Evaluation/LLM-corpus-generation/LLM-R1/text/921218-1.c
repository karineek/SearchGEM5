// Modification timestamp: 2023-08-14 13:32:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921218-1.c
f()
{
  return (unsigned char)("\377"[0]);
}

main()
{
  if (f() != (unsigned char)(0377))
    abort();
  exit (0);
}
