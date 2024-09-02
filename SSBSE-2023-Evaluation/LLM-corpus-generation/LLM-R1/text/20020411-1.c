// Modification timestamp: 2023-08-14 12:15:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020411-1.c
/* PR optimization/6177
   This testcase ICEd because expr.c did not expect to see a CONCAT
   as array rtl.  */

extern void abort (void);
extern void exit (int);

__complex__ float foo (void)
{
  __complex__ float f[1];
  __real__ f[0] = 1.0;
  __imag__ f[0] = 1.0;
  f[0] = __builtin_conjf (f[0]);
  return f[0];
}

int main (void)
{
  __complex__ double d[1];
  d[0] = foo ();
  if (__real__ d[0] != 1.0
      || __imag__ d[0] != -1.0)
    abort ();
  exit (0);
}
