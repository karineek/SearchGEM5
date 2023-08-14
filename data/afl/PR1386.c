// Modification timestamp: 2023-08-14 17:33:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//PR1386.c

#include <stdio.h>
#include <stdint.h>

struct X {
  unsigned char pad : 4;
  uint64_t a : 64;
  uint64_t b : 60;
} __attribute__((packed));

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <pad> <a> <b>\n", argv[0]);
    return 1;
  }

  struct X x;
  uint64_t bad_bits;

  x.pad = atoi(argv[1]);
  x.a = strtoull(argv[2], NULL, 0);
  x.b = strtoull(argv[3], NULL, 0);

  bad_bits = ((uint64_t)-1ULL) ^ *(1+(uint64_t *) &x);
  printf("bad bits: %llx\n", bad_bits);
  return bad_bits != 0;
}

