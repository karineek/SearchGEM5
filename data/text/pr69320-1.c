// Modification timestamp: 2023-08-14 15:48:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69320-1.c
#include <stdlib.h>
int a, b, d, f;
char c;
static int *e = &d;
int main() {
  int g = -1L;
  *e = g;
  c = 4;
  for (; c >= 14; c++)
    *e = 1;
  f = a == 0;
  *e ^= f;
  int h = ~d;
  if (d)
    b = h;
  if (h)
    exit (0);
  abort ();
}
