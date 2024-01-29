// Modification timestamp: 2023-08-14 15:48:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69097-1.c
/* PR tree-optimization/69097 */

int a, b;
unsigned int c;

int
main ()
{
  int d = b;
  b = ~(~a + (~d | b));
  a = ~(~c >> b);
  c = a % b;
  return 0;
}
