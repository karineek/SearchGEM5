// Modification timestamp: 2023-08-14 13:40:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/940122-1.c
char *a = 0;
char *b = 0;

g (x)
     int x;
{
  if ((!!a) != (!!b))
    abort ();
}

f (x)
     int x;
{
  g (x * x);
}

main ()
{
  f (100);
  exit (0);
}
