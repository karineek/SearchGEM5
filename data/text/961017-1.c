// Modification timestamp: 2023-08-14 13:47:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961017-1.c
main ()
{
  unsigned char z = 0;

  do ;
  while (--z > 0);
  exit (0);
}
