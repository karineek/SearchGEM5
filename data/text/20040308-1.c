// Modification timestamp: 2023-08-14 12:51:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040308-1.c
/* { dg-require-effective-target alloca } */
/* This used to fail on SPARC with an unaligned memory access.  */

void foo(int n)
{
  struct S {
    int i[n];
    unsigned int b:1;
    int i2;
  } __attribute__ ((packed)) __attribute__ ((aligned (4)));

  struct S s;

  s.i2 = 0;
}

int main(void)
{
  foo(4);

  return 0;
}
