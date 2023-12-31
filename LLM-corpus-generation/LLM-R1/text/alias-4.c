// Modification timestamp: 2023-08-14 13:59:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-4.c
/* { dg-require-alias "" } */
int a = 1;
extern int b __attribute__ ((alias ("a")));
int c = 1;
extern int d __attribute__ ((alias ("c")));
main (int argc)
{
  int *p;
  int *q;
  if (argc)
    p = &a, q = &b;
  else
    p = &c, q = &d;
  *p = 1;
  *q = 2;
  if (*p == 1)
    __builtin_abort ();
  return 0;
}
