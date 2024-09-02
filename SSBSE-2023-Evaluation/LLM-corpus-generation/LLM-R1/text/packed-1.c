// Modification timestamp: 2023-08-14 14:42:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/packed-1.c
short x1 = 17;

struct
{
  short i __attribute__ ((packed));
} t;

f ()
{
  t.i = x1;
  if (t.i != 17)
    abort ();
}

main ()
{
  f ();
  exit (0);
}
