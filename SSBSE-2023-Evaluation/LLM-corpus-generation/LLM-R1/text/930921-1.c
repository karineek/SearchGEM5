// Modification timestamp: 2023-08-14 13:35:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930921-1.c
f (x)
     unsigned x;
{
  return (unsigned) (((unsigned long long) x * 0xAAAAAAAB) >> 32) >> 1;
}

main ()
{
  unsigned i;

  for (i = 0; i < 10000; i++)
    if (f (i) != i / 3)
      abort ();
  exit (0);
}
