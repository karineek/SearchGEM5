// Modification timestamp: 2023-08-14 12:45:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030401-1.c
/* Testcase for PR fortran/9974.  This was a miscompilation of the g77
   front-end caused by the jump bypassing optimizations not handling
   instructions inserted on CFG edges.  */

extern void abort ();

int bar ()
{
  return 1;
}

void foo (int x)
{
  unsigned char error = 0;

  if (! (error = ((x == 0) || bar ())))
    bar ();
  if (! error)
    abort ();
}

int main()
{
  foo (1);
  return 0;
}
