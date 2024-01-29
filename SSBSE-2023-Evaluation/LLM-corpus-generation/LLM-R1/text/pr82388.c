// Modification timestamp: 2023-08-14 15:57:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr82388.c
/* PR tree-optimization/82388 */

struct A { int b; int c; int d; } e;

struct A
foo (void)
{
  struct A h[30] = {{0,0,0}};
  return h[29];
}

int
main ()
{
  e = foo ();
  return e.b;
}
