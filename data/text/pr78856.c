// Modification timestamp: 2023-08-14 15:53:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78856.c
extern void exit (int);

int a, b, c, d, e, f[3];

int main()
{
  while (d)
    while (1)
      ;
  int g = 0, h, i = 0;
  for (; g < 21; g += 9)
    {
      int j = 1;
      for (h = 0; h < 3; h++)
	f[h] = 1;
      for (; j < 10; j++) {
	d = i && (b ? 0 : c);
	i = 1;
	if (g)
	  a = e;
      }
  }
  exit (0);
}
