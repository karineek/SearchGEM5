// Modification timestamp: 2023-08-14 14:05:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bf-sign-1.c
main ()
{
  struct  {
    signed int s:3;
    unsigned int u:3;
    int i:3;
  } x = {-1, -1, -1};

  if (x.u != 7)
    abort ();
  if (x.s != - 1)
    abort ();

  if (x.i != -1 && x.i != 7)
    abort ();

  exit (0);
}
