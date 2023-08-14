// Modification timestamp: 2023-08-14 15:00:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37882.c
/* PR middle-end/37882 */

struct S
{
  unsigned char b : 3;
} s;

int
main ()
{
  s.b = 4;
  if (s.b > 0 && s.b < 4)
    __builtin_abort ();
  return 0;
}
