// Modification timestamp: 2023-08-14 12:07:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020107-1.c
/* This testcase failed because - 1 - buf was simplified into ~buf and when
   later expanding it back into - buf + -1, -1 got lost.  */
/* { dg-options "-fgnu89-inline" } */

extern void abort (void);
extern void exit (int);

static void
bar (int x)
{
  if (!x)
    abort ();
}

char buf[10];

inline char *
foo (char *tmp)
{
  asm ("" : "=r" (tmp) : "0" (tmp));
  return tmp + 2;
}

int
main (void)
{
  bar ((foo (buf) - 1 - buf) == 1);
  exit (0);
}
