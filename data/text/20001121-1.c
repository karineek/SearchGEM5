// Modification timestamp: 2023-08-14 11:54:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001121-1.c
/* { dg-options "-fgnu89-inline" } */

extern void abort (void);
extern void exit (int);

double d;

__inline__ double foo (void)
{
  return d;
}

__inline__ int bar (void)
{
  foo();
  return 0;
}

int main (void)
{
  if (bar ())
    abort ();
  exit (0);
}
