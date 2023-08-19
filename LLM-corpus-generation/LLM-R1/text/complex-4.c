// Modification timestamp: 2023-08-14 14:18:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-4.c
main ()
{
  if ((__complex__ double) 0.0 != (__complex__ double) (-0.0))
    abort ();

  if (0.0 != -0.0)
    abort ();
  exit (0);
}
