// Modification timestamp: 2023-08-14 13:40:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941025-1.c
long f (x, y)
     long x,y;
{
  return (x > 1) ? y : (y & 1);
}

main ()
{
  if (f (2L, 0xdecadeL) != 0xdecadeL)
    abort ();
  exit (0);
}
