// Modification timestamp: 2023-08-14 15:51:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71550.c

extern void exit (int);

int a = 3, b, c, f, g, h;
unsigned d;
char *e;

int
main ()
{
  for (; a; a--)
    {
      int i;
      if (h && i)
	__builtin_printf ("%d%d", c, f);
      i = 0;
      for (; i < 2; i++)
	if (g)
	  for (; d < 10; d++)
	    b = *e;
      i = 0;
      for (; i < 1; i++)
	;
    }
  exit (0);
}
