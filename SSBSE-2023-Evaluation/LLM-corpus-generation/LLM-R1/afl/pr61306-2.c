// Modification timestamp: 2023-08-14 15:38:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61306-2.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __INT16_TYPE__
typedef __INT16_TYPE__ int16_t;
#else
typedef short int16_t;
#endif

#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ uint32_t;
#else
typedef unsigned uint32_t;
#endif

#define __fake_const_swab32(x) ((uint32_t)( \
    (((uint32_t) (x) & (uint32_t)0x000000ffUL) << 24) | \
    (((uint32_t)(int16_t)(x) & (uint32_t)0x00ffff00UL) << 8) | \
    (((uint32_t) (x) & (uint32_t)0x00ff0000UL) >> 8) | \
    (((uint32_t) (x) & (uint32_t)0xff000000UL) >> 24)))

/* Previous version of bswap optimization failed to consider sign extension
   and as a result would replace an expression *not* doing a bswap by a
   bswap.  */

__attribute__ ((noinline, noclone)) uint32_t
fake_bswap32(uint32_t in) {
  return __fake_const_swab32(in);
}

int main(int argc, char *argv[]) {
  if (sizeof(uint32_t) * __CHAR_BIT__ != 32)
    return 0;
  if (sizeof(int16_t) * __CHAR_BIT__ != 16)
    return 0;
  if (fake_bswap32(atoi(argv[1])) != 0xff838281)
    __builtin_abort();
  return 0;
}
