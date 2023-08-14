
// Modification timestamp: 2023-08-10 15:32:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/coverage/2020-01-06-coverage-003.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int8_t a;
int32_t x;

void b() { x = (uint64_t)4073709551607 > a || a != 0; }

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <val_1> <val_2>\n", argv[0]);
    return 1;
  }

  int8_t val_1 = atoi(argv[1]);
  int32_t val_2 = atoi(argv[2]);

  x = val_2;
  a = val_1;
  b();

  printf("a = %" PRIi8 "\n", a);
  printf("x = %" PRIi32 "\n", x);

  return 0;
}
