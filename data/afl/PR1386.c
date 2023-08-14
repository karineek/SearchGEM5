c
// Modification timestamp: 2023-08-10 15:58:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/FreeBench/distray/PR1386.c

#include <stdio.h>
#include <stdint.h>

struct X {
  unsigned char pad : 4;
  uint64_t a : 64;
  uint64_t b : 60;
} __attribute__((packed));

int main(void)
{
  struct X x;
  uint64_t bad_bits;

  x.pad = 255;

  if (argc != 4) {
    printf("Usage: %s <pad> <a> <b>\n", argv[0]);
    return 1;
  }

  x.a = atoi(argv[1]);
  x.b = atoi(argv[2]);

  bad_bits = ((uint64_t)-1ULL) ^ *(1 + (uint64_t *)&x);
  printf("bad bits: %llx\n", bad_bits);
  return bad_bits != 0;
}
