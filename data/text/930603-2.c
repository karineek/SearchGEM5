// Modification timestamp: 2023-08-14 13:34:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930603-2.c
int w[2][2];

f ()
{
  int i, j;

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      if (i == j)
	w[i][j] = 1;
}

main ()
{
  f ();
  if (w[0][0] != 1 || w[1][1] != 1 || w[1][0] != 0 || w[0][1] != 0)
    abort ();
  exit (0);
}
