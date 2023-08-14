// Modification timestamp: 2023-08-14 12:35:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020720-1.c
/* Copyright (C) 2002  Free Software Foundation.

   Ensure that fabs(x) < 0.0 optimization is working.

   Written by Roger Sayle, 20th July 2002.  */

extern void abort (void);
extern double fabs (double);
extern void link_error (void);

void
foo (double x)
{
  double p, q;

  p = fabs (x);
  q = 0.0;
  if (p < q)
    link_error ();
}

int
main()
{
  foo (1.0);
  return 0;
}

#ifndef __OPTIMIZE__
void
link_error ()
{
  abort ();
}
#endif
