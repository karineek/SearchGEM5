// Modification timestamp: 2023-08-14 13:46:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960801-1.c
unsigned
f ()
{
  long long l2;
  unsigned short us;
  unsigned long long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}

unsigned long long
g ()
{
  long long l2;
  unsigned short us;
  unsigned long long ul;
  short s2;

  ul = us = l2 = s2 = -1;
  return ul;
}

main ()
{
  if (f () != (unsigned short) -1)
    abort ();
  if (g () != (unsigned short) -1)
    abort ();
  exit (0);
}
