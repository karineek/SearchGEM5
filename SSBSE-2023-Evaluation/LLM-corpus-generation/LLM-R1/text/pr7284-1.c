// Modification timestamp: 2023-08-14 15:51:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr7284-1.c
/* Signed left-shift is implementation-defined in C89 (and see
   DR#081), not undefined.  Bug 7284 from Al Grant (AlGrant at
   myrealbox.com).  */

/* { dg-require-effective-target int32plus } */
/* { dg-options "-std=c89" } */

extern void abort (void);
extern void exit (int);

int
f (int n)
{
  return (n << 24) / (1 << 23);
}

volatile int x = 128;

int
main (void)
{
  if (f(x) != -256)
    abort ();
  exit (0);
}
