// Modification timestamp: 2023-08-14 16:10:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/simd-4.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int32_t __attribute__((vector_size(8))) v2si;
int64_t s64;

static inline int64_t
__ev_convert_s64 (v2si a)
{
  return (int64_t) a;
}

int main(int argc, char *argv[]) {
  union { int64_t ll; int32_t i[2]; } endianness_test;
  endianness_test.ll = atoi(argv[1]);
  int32_t little_endian = endianness_test.i[0];
  s64 = __ev_convert_s64 ((v2si){1,0xffffffff});
  if (s64 != (little_endian ? 0xffffffff00000001LL : 0x1ffffffffLL))
    abort ();
  return 0;
}
