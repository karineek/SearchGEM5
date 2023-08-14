// Modification timestamp: 2023-08-14 13:59:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/align-3.c
/* { dg-skip-if "small alignment" { pdp11-*-* } } */

void func(void) __attribute__((aligned(256)));

void func(void)
{
}

int main()
{
  if (__alignof__(func) != 256)
    abort ();
  return 0;
}
