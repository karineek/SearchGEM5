// Modification timestamp: 2023-08-14 17:32:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2008-01-07-LongDouble.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  long double x = atof(argv[1]);
  long double y = atof(argv[2]);
  printf("%Lf %Lf\n", x, y);
  return 0;
}
