// Modification timestamp: 2023-08-14 13:08:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070424-1.c
extern void abort (void);
extern void exit (int);

void do_exit (void) { exit (0); }
void do_abort (void) { abort (); }

void foo (int x, int a)
{
  if (x < a)
    goto doit;
  do_exit ();
  if (x != a)
    goto doit;

  /* else */
  do_abort ();
  return;

doit:
  do_abort ();
}

int main()
{
  foo (1, 0);
  return 0;
}
