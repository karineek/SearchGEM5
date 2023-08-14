// Modification timestamp: 2023-08-14 13:58:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-3.c
/* { dg-require-alias "" } */
/* { dg-skip-if "" { powerpc-ibm-aix* } } */
static int a=0;
extern int b __attribute__ ((alias("a")));
__attribute__ ((noinline))
static inc()
{
  b++;
}
int
main()
{
  a=0;
  inc ();
  if (a!=1)
    __builtin_abort ();
  return 0;
}
