// Modification timestamp: 2023-08-14 13:00:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041213-2.c
/* PR tree-optimization/18694

   The dominator optimization didn't take the PHI evaluation order
   into account when threading an edge.  */

extern void abort (void) __attribute__((noreturn));
extern void exit (int) __attribute__((noreturn));

void __attribute__((noinline))
foo (int i)
{
  int next_n = 1;
  int j = 0;

  for (; i != 0; i--)
    {
      int n;

      for (n = next_n; j < n; j++)
	next_n++;

      if (j != n)
	abort ();
    }
}

int
main (void)
{
  foo (2);
  exit (0);
}
