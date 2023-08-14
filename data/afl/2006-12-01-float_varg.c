
// Modification timestamp: 2023-08-10 15:14:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2006-12-01-float_varg.c

#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
    return 1;
  }

  printf("foo %f %f %f %f\n", atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]));
  return 0;
}
