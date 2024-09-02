// Modification timestamp: 2023-08-14 14:31:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-4b.c
int
f()
{
  int j = 1;
  long i;
  i = 0x60000000L;
  do
    {
      j <<= 1;
      i += 0x10000000L;
    } while (i < -0x60000000L);
  return j;
}

int
main ()
{
  if (f () != 2)
    abort ();
  exit (0);
}
