// Modification timestamp: 2023-08-14 15:17:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48973-2.c
/* PR middle-end/48973 */

extern void abort (void);
struct S { int f : 1; } s;
int v = -1;

int
main ()
{
  s.f = v < 0;
  if ((unsigned int) s.f != -1U)
    abort ();
  return 0;
}
