// Modification timestamp: 2023-08-14 17:30:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/testcase-InstCombine-1.c

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct S {
  int32_t a : 18;
  int32_t b : 1;
  int32_t c : 24;
  int32_t d : 15;
  int32_t e : 14;
} h;

int f;
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int main_arg = atoi(argv[1]);
  for (; f; f++) {
    struct S m = {5, 0, -5, 9, 5};
    h = m;
  }
  
  if (h.d != (long)0 - h.d * h.d)
    printf("1");

  return 0;
}
