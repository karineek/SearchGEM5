// Modification timestamp: 2023-08-14 15:36:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59221.c
/* { dg-xfail-if "ptxas crashes" { nvptx-*-* } { "*" } { "-O0" "-Os" } } */


int a = 1, b, d;
short e;

int
main ()
{
  for (; b; b++)
    ;
  short f = a;
  int g = 15;
  e = f ? f : 1 << g;
  int h = e;
  d = h == 83647 ? 0 : h;
  if (d != 1)
    __builtin_abort ();
  return 0;
}
