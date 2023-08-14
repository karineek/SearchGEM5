// Modification timestamp: 2023-08-14 15:17:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49123.c
/* PR lto/49123 */

extern void abort (void);
static struct S { int f : 1; } s;
static int v = -1;

int
main ()
{
  s.f = v < 0;
  if ((unsigned int) s.f != -1U)
    abort ();
  return 0;
}
