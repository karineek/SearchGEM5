// Modification timestamp: 2023-08-14 13:41:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950605-1.c
f (c)
    unsigned char c;
{
  if (c != 0xFF)
    abort ();
}

main ()
{
  f (-1);
  exit (0);
}
