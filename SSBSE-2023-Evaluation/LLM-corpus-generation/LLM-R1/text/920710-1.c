// Modification timestamp: 2023-08-14 13:28:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920710-1.c
main()
{
  if ((double) 18446744073709551615ULL < 1.84467440737095e+19 ||
      (double) 18446744073709551615ULL > 1.84467440737096e+19)
    abort();

  if (16777217L != (float)16777217e0)
    abort();

  exit(0);
}
