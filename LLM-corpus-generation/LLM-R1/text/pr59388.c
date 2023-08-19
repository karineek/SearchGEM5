// Modification timestamp: 2023-08-14 15:36:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59388.c
/* PR tree-optimization/59388 */

int a;
struct S { unsigned int f:1; } b;

int
main ()
{
  a = (0 < b.f) | b.f;
  return a;
}
