// Modification timestamp: 2023-08-14 13:43:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/951115-1.c
int var = 0;

g ()
{
  var = 1;
}

f ()
{
  int f2 = 0;

  if (f2 == 0)
    ;

  g ();
}

main ()
{
  f ();
  if (var != 1)
    abort ();
  exit (0);
}
