// Modification timestamp: 2023-08-14 13:20:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120111-1.c
#include <stdlib.h>
#include <stdint.h>

uint32_t f0a (uint64_t arg2) __attribute__((noinline));

uint32_t
f0a (uint64_t arg)
{
  return ~((unsigned) (arg > -3));
}

int main() {
  uint32_t r1;
  r1 = f0a (12094370573988097329ULL);
  if (r1 != ~0U)
    abort ();
  return 0;
}
