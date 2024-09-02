// Modification timestamp: 2023-08-14 15:35:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58943.c
/* PR c/58943 */

unsigned int x[1] = { 2 };

unsigned int
foo (void)
{
  x[0] |= 128;
  return 1;
}

int
main ()
{
  x[0] |= foo ();
  if (x[0] != 131)
    __builtin_abort ();
  return 0;
}
