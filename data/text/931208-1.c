// Modification timestamp: 2023-08-14 13:39:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931208-1.c
f ()
{
  unsigned long x, y = 1;

  x = ((y * 8192) - 216) / 16;
  return x;
}

main ()
{
  if (f () != 498)
    abort ();
  exit (0);
}
