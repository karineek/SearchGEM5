// Modification timestamp: 2023-08-14 15:22:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52209.c
/* PR middle-end/52209 */

extern void abort (void);
struct S0 { int f2 : 1; } c;
int b;

int
main ()
{
  b = -1 ^ c.f2;
  if (b != -1)
    abort ();
  return 0;
}
