// Modification timestamp: 2023-08-14 13:42:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950621-1.c
struct s
{
  int a;
  int b;
  struct s *dummy;
};

f (struct s *sp)
{
  return sp && sp->a == -1 && sp->b == -1;
}

main ()
{
  struct s x;
  x.a = x.b = -1;
  if (f (&x) == 0)
    abort ();
  exit (0);
}
