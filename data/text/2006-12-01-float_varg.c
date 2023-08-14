
// Modification timestamp: 2023-08-10 15:14:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2006-12-01-float_varg.c

#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("foo %f %f %f %f\n", 1.23, 12312.1, 3.1, 13.1);
  return 0;
}
