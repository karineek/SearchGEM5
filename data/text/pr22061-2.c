// Modification timestamp: 2023-08-14 14:45:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22061-2.c
int *x;
static void bar (char a[2][(*x)++]) {}
int
main (void)
{
  exit (0);
}
