// Modification timestamp: 2023-08-14 12:09:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020118-1.c
/* This tests an insn length of sign extension on h8300 port.  */

extern void exit (int);

volatile signed char *q;
volatile signed int n;

void
foo (void)
{
  signed char *p;

  for (;;)
    {
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
      p = (signed char *) q; n = p[2];
    }
}

int
main ()
{
  exit (0);
}
