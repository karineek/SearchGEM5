
// Modification timestamp: 2023-08-10 15:34:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/IntBench/Cov/2020-01-06-coverage-006.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#pragma pack(1)

struct s {
  int : 28;
  unsigned : 17;
  unsigned a : 25;
} b;

volatile int32_t c;
int32_t x;

void d() {
  if (8 < b.a)
    x = c;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <val_1> <val_2> <val_3>\n", argv[0]);
    return 1;
  }

  uint32_t val_1 = atoi(argv[1]);
  int32_t val_2 = atoi(argv[2]);
  int32_t val_3 = atoi(argv[3]);

  x = val_3;
  c = val_2;
  b.a = val_1;
  d();

  printf("b.a = %u\n", b.a);
  printf("c = %" PRIi32 "\n", c);
  printf("x = %" PRIi32 "\n", x);

  return 0;
}
