// Modification timestamp: 2023-08-14 15:48:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69320-3.c
#include <stdlib.h>

static int a[40] = {7, 5, 3, 3, 0, 0, 3};
short b;
int c = 5;
int main() {
  b = 0;
  for (; b <= 3; b++)
    if (a[b + 6] ^ (0 || c))
      ;
    else
      break;
  if (b != 4)
    abort ();
  exit (0);
}