// Modification timestamp: 2023-08-14 13:49:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980506-2.c
static void *self(void *p){ return p; }

int
f()
{
  struct { int i; } s, *sp;
  int *ip = &s.i;

  s.i = 1;
  sp = self(&s);

  *ip = 0;
  return sp->i+1;
}

main()
{
  if (f () != 1)
    abort ();
  else
    exit (0);
}
