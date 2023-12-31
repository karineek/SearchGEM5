// Modification timestamp: 2023-08-14 12:41:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021204-1.c
/* This test was miscompiled when using sibling call optimization,
   because X ? Y : Y - 1 optimization changed X into !X in place
   and haven't reverted it if do_store_flag was successful, so
   when expanding the expression the second time it was
   !X ? Y : Y - 1.  */

extern void abort (void);
extern void exit (int);

void foo (int x)
{
  if (x != 1)
    abort ();
}

int z;

int main (int argc, char **argv)
{
  char *a = "test";
  char *b = a + 2;

  foo (z > 0 ? b - a : b - a - 1);
  exit (0);
}
