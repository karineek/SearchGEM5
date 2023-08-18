// Modification timestamp: 2023-08-14 13:56:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990829-1.c

#include <stdio.h>
#include <stdlib.h>

double test(const double le, const double ri) {
  double val = (ri - le) / (ri * (le + 1.0));
  return val;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <le> <ri>\n", argv[0]);
    return 1;
  }

  double le = atof(argv[1]);
  double ri = atof(argv[2]);

  double retval = test(le, ri);
  if (retval < 0.24 || retval > 0.26)
    abort();

  exit(0);
}
