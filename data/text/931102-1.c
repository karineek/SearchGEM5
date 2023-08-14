// Modification timestamp: 2023-08-14 13:39:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931102-1.c
typedef union
{
  struct
    {
      char h, l;
    } b;
} T;

f (x)
     int x;
{
  int num = 0;
  T reg;

  reg.b.l = x;
  while ((reg.b.l & 1) == 0)
    {
      num++;
      reg.b.l >>= 1;
    }
  return num;
}

main ()
{
  if (f (2) != 1)
    abort ();
  exit (0);
}
