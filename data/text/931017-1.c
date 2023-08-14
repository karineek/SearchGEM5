// Modification timestamp: 2023-08-14 13:39:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931017-1.c
int v;

main ()
{
  f ();
  exit (0);
}

h1 ()
{
  return 0;
}

h2 (e)
     int *e;
{
  if (e != &v)
    abort ();
  return 0;
}

g (c)
     char *c;
{
  int i;
  int b;

  do
    {
      i = h1 ();
      if (i == -1)
	return 0;
      else if (i == 1)
	h1 ();
    }
  while (i == 1);

  do
    b = h2 (&v);
  while (i == 5);

  if (i != 2)
    return b;
  *c = 'a';

  return 0;
}


f ()
{
  char c;
  g (&c);
}
