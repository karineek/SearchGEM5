// Modification timestamp: 2023-08-14 13:47:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960909-1.c
int
ffs (x)
     int x;
{
  int bit, mask;

  if (x == 0)
    return 0;

  for (bit = 1, mask = 1; !(x & mask); bit++, mask <<= 1)
    ;

  return bit;
}

f (x)
     int x;
{
  int y;
  y = ffs (x) - 1;
  if (y < 0)
    abort ();
}

main ()
{
  f (1);
  exit (0);
}
