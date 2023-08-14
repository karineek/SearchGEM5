// Modification timestamp: 2023-08-14 13:40:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941021-1.c
double glob_dbl;

f (pdbl, value)
     double *pdbl;
     double value;
{
  if (pdbl == 0)
    pdbl = &glob_dbl;

  *pdbl = value;
}

main ()
{
  f ((void *) 0, 55.1);

  if (glob_dbl != 55.1)
    abort ();
  exit (0);
}
