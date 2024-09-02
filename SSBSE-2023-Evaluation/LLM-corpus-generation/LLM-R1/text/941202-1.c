// Modification timestamp: 2023-08-14 13:41:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941202-1.c
/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
g (x, y)
{
  if (x != 3)
    abort ();
}

static inline
f (int i)
{
  int *tmp;

  tmp = (int *) alloca (sizeof (i));
  *tmp = i;
  g (*tmp, 0);
}

main ()
{
  f (3);
  exit (0);
};
