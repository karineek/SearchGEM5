// Modification timestamp: 2023-08-14 12:38:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021118-3.c
extern void abort (void);
extern void exit (int);

int
foo (int x)
{
  if (x == -2 || -x - 100 >= 0)
    abort ();
  return 0;
}

int
main ()
{
  foo (-3);
  foo (-99);
  exit (0);
}
