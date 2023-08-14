// Modification timestamp: 2023-08-14 13:43:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950714-1.c
int array[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

main ()
{
  int i, j;
  int *p;

  for (i = 0; i < 10; i++)
    for (p = &array[0]; p != &array[9]; p++)
      if (*p == i)
	goto label;

 label:
  if (i != 1)
    abort ();
  exit (0);
}
