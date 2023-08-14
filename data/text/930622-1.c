// Modification timestamp: 2023-08-14 13:34:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930622-1.c
int a = 1, b;

g () { return 0; }
h (x) {}

f ()
{
  if (g () == -1)
    return 0;
  a = g ();
  if (b >= 1)
    h (a);
  return 0;
}

main ()
{
  f ();
  if (a != 0)
    abort ();
  exit (0);
}
