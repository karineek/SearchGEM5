// Modification timestamp: 2023-08-14 13:37:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-3.c
struct tiny
{
  short c;
};

f (int n, struct tiny x, struct tiny y, struct tiny z, long l)
{
  if (x.c != 10)
    abort();

  if (y.c != 11)
    abort();

  if (z.c != 12)
    abort();

  if (l != 123)
    abort ();
}

main ()
{
  struct tiny x[3];
  x[0].c = 10;
  x[1].c = 11;
  x[2].c = 12;
  f (3, x[0], x[1], x[2], (long) 123);
  exit(0);
}