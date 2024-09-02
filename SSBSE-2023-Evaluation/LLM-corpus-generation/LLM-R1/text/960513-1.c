// Modification timestamp: 2023-08-14 13:46:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960513-1.c
long double
f (d, i)
     long double d;
     int i;
{
  long double e;

  d = -d;
  e = d;
  if (i == 1)
    d *= 2;
  d -= e * d;
  d -= e * d;
  d -= e * d;
  d -= e * d;
  d -= e * d;
  return d;
}

main ()
{
  if (! (int) (f (2.0L, 1)))
    abort ();
  exit (0);
}
