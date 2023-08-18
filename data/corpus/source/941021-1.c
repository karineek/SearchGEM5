// Modification timestamp: 2023-08-14 13:40:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941021-1.c

#include <stdio.h>
#include <stdlib.h>

double glob_dbl;

void f(double *pdbl, double value) {
  if (pdbl == 0)
    pdbl = &glob_dbl;

  *pdbl = value;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <pdbl> <value>\n", argv[0]);
    return 1;
  }

  double *pdbl = atoi(argv[1]) == 0 ? NULL : &glob_dbl;
  double value = atof(argv[2]);

  f(pdbl, value);

  if (glob_dbl != value)
    abort();
  
  exit(0);
}
