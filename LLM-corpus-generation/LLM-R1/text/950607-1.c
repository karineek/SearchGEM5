// Modification timestamp: 2023-08-14 13:42:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950607-1.c
main ()
{
  struct { long status; } h;

  h.status = 0;
  if (((h.status & 128) == 1) && ((h.status & 32) == 0))
    abort ();
  exit (0);
}
