// Modification timestamp: 2023-08-14 15:15:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47155.c
/* PR tree-optimization/47155 */

unsigned int a;
static signed char b = -127;
int c = 1;

int
main (void)
{
  a = b <= (unsigned char) (-6 * c);
  if (!a)
    __builtin_abort ();
  return 0;
}
