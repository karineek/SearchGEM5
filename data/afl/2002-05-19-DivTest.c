// Modification timestamp: 2023-08-14 17:11:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-19-DivTest.c


#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int B20 = atoi(argv[1]);
  int64_t B53 = atoi(argv[2]);

  printf("%d\n", B20 / (1 << 0));
  printf("%d\n", B20 / (1 << 4));
  printf("%d\n", B20 / (1 << 18));
  printf("%d\n", B20 / (1 << 30));

  printf("%d\n", (int) (B53 / ((int64_t)1 << 4)));
  printf("%d\n", (int) (B53 / ((int64_t)1 << 46)));

  return 0;
}
