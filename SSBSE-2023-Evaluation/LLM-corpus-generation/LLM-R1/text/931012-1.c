// Modification timestamp: 2023-08-14 13:39:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931012-1.c
f (int b, int c)
{
  if (b != 0 && b != 1 && c != 0)
    b = 0;
  return b;
}

main ()
{
  if (!f (1, 2))
    abort();
  exit(0);
}
