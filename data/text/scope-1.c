// Modification timestamp: 2023-08-14 16:09:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/scope-1.c
int v = 3;

f ()
{
  int v = 4;
  {
    extern int v;
    if (v != 3)
      abort ();
  }
}

main ()
{
  f ();
  exit (0);
}
