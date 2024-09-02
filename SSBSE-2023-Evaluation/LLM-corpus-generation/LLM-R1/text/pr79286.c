// Modification timestamp: 2023-08-14 15:54:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79286.c
int a = 0, c = 0;
static int d[][8] = {};

int main ()
{
  int e = 0;
  for (int b = 0; b < 4; b++)
    {
      __builtin_printf ("%d\n", b, e);
      while (a && c++)
	e = d[300000000000000000][0];
    }

  return 0;
}
