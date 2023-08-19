// Modification timestamp: 2023-08-14 14:22:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/dbra-1.c
f1 (a)
     long a;
{
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a == -1)
	return i;
    }
  return -1;
}

f2 (a)
     long a;
{
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a != -1)
	return i;
    }
  return -1;
}

f3 (a)
     long a;
{
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a == 0)
	return i;
    }
  return -1;
}

f4 (a)
     long a;
{
  int i;
  for (i = 0; i < 10; i++)
    {
      if (--a != 0)
	return i;
    }
  return -1;
}

f5 (a)
     long a;
{
  int i;
  for (i = 0; i < 10; i++)
    {
      if (++a == 0)
	return i;
    }
  return -1;
}

f6 (a)
     long a;
{
  int i;
  for (i = 0; i < 10; i++)
    {
      if (++a != 0)
	return i;
    }
  return -1;
}


main()
{
  if (f1 (5L) != 5)
    abort ();
  if (f2 (1L) != 0)
    abort ();
  if (f2 (0L) != 1)
    abort ();
  if (f3 (5L) != 4)
    abort ();
  if (f4 (1L) != 1)
    abort ();
  if (f4 (0L) != 0)
    abort ();
  if (f5 (-5L) != 4)
    abort ();
  if (f6 (-1L) != 1)
    abort ();
  if (f6 (0L) != 0)
    abort ();
  exit (0);
}
