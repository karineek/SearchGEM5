// Modification timestamp: 2023-08-14 13:58:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-2.c
/* { dg-require-alias "" } */
int a[10]={};
extern int b[10] __attribute__ ((alias("a")));
int off;
main()
{
  b[off]=1;
  a[off]=2;
  if (b[off]!=2)
   __builtin_abort ();
  return 0;
}
