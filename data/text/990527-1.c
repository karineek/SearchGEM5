// Modification timestamp: 2023-08-14 13:55:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990527-1.c
int sum;

void
g (int i)
{
  sum += i;
}

void
f(int j)
{
  int i;

  for (i = 0; i < 9; i++)
    {
      j++;
      g (j);
      j = 9;
    }
}

int
main ()
{
  f (0);
  if (sum != 81)
    abort ();
  exit (0);
}
