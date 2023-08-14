// Modification timestamp: 2023-08-14 15:36:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59413.c
/* PR tree-optimization/59413 */

typedef unsigned int uint32_t;

uint32_t a;
int b;

int
main ()
{
  uint32_t c;
  for (a = 7; a <= 1; a++)
    {
      char d = a;
      c = d;
      b = a == c;
    }
  if (a != 7)
    __builtin_abort ();
  return 0;
}
