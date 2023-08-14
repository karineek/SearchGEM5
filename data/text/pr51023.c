// Modification timestamp: 2023-08-14 15:19:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr51023.c
/* PR rtl-optimization/51023 */

extern void abort (void);

short int
foo (long int x)
{
  return x;
}

int
main ()
{
  long int a = 0x4272AL;
  if (foo (a) == a)
    abort ();
  return 0;
}
