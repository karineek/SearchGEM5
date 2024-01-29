// Modification timestamp: 2023-08-14 15:18:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49644.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

int main(int argc, char *argv[]) {
  _Complex double a[12], *c = a, s = atof(argv[1]) + atof(argv[2]) * I;
  double b[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }, *d = b;
  int i;
  for (i = 0; i < 6; i++)
    *c++ = *d++ * s;
  if (c != a + 6 || d != b + 6)
    abort ();
  return 0;
}
