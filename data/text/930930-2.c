// Modification timestamp: 2023-08-14 13:36:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930930-2.c
int
test_endianness()
{
  union doubleword
    {
      double d;
      unsigned long u[2];
    } dw;
  dw.d = 10;
  return dw.u[0] != 0 ? 1 : 0;
}

int
test_endianness_vol()
{
  union doubleword
    {
      volatile double d;
      volatile long u[2];
    } dw;
  dw.d = 10;
  return dw.u[0] != 0 ? 1 : 0;
}

main ()
{
  if (test_endianness () != test_endianness_vol ())
    abort ();
  exit (0);
}
