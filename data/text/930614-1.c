// Modification timestamp: 2023-08-14 13:34:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930614-1.c
f (double *ty)
{
  *ty = -1.0;
}

main ()
{
  double foo[6];
  double tx = 0.0, ty, d;

  f (&ty);

  if (ty < 0)
    ty = -ty;
  d = (tx > ty) ? tx : ty;
  if (ty != d)
    abort ();
  exit (0);
}
