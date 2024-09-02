// Modification timestamp: 2023-08-14 15:17:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49186.c
/* PR target/49186 */
extern void abort (void);

int
main ()
{
  int x;
  unsigned long long uv = 0x1000000001ULL;

  x = (uv < 0x80) ? 1 : ((uv < 0x800) ? 2 : 3);
  if (x != 3)
    abort ();

  return 0;
}
