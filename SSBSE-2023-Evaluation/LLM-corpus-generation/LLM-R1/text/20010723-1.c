// Modification timestamp: 2023-08-14 11:59:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010723-1.c
int
test ()
{
  int biv,giv;
  for (biv = 0, giv = 0; giv != 8; biv++)
      giv = biv*8;
  return giv;
}


main()
{
  if (test () != 8)
    abort ();
  exit (0);
}
