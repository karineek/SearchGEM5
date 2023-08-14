
// Modification timestamp: 2023-08-10 15:34:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/MiBench/telecomm-crc32/telecomm-crc32.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

uint32_t a;
const uint32_t b = -1L, c;
int16_t d;

void e() {
  uint32_t f;
  uint32_t g;
  f = b / a;
  g = f;
  d = g < c;
}

int main(int argc, char *argv[]) {
  int16_t val_2;
  uint32_t val_1;

  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  val_1 = atoi(argv[1]);
  val_2 = atoi(argv[2]);

  d = val_2;
  a = val_1;
  e();

  printf("a = %" PRIu32 "\n", a);
  printf("b = %" PRIu32 "\n", b);
  printf("c = %" PRIu32 "\n", c);
  printf("d = %" PRIi16 "\n", d);

  return 0;
}
