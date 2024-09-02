// Modification timestamp: 2023-08-14 13:25:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920411-1.c

#include <stdio.h>
#include <stdlib.h>

long f (char *w) {
  long k, i, c = 0, x;
  char *p = (char*) &x;
  for (i = 0; i < 1; i++) {
    for (k = 0; k < sizeof (long); k++)
      p[k] = w[k];
    c += x;
  }
  return c;
}

int main(int argc, char *argv[]) {
  int i;
  char a[sizeof (long)];

  for (i = sizeof (long); --i >= 0;) a[i] = argv[1][0];
  if (f (a) != ~0UL / (unsigned char) ~0 * argv[2][0]) abort ();

  exit (0);
}
