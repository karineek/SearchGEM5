// Modification timestamp: 2023-08-14 14:41:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-5.c
/* { dg-require-effective-target trampolines } */

extern void abort (void);
extern void exit (int);

static void recursive (int n, void (*proc) (void))
{
  __label__ l1;

  void do_goto (void)
  {
    goto l1;
  }

  if (n == 3)
      recursive (n - 1, do_goto);
  else if (n > 0)
    recursive (n - 1, proc);
  else
    (*proc) ();
  return;

l1:
  if (n == 3)
    exit (0);
  else
    abort ();
}

int main ()
{
  recursive (10, abort);
  abort ();
}
