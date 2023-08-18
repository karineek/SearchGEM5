// Modification timestamp: 2023-08-14 15:37:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60454.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ uint32_t;
#else
typedef unsigned uint32_t;
#endif

#define __fake_const_swab32(x) ((uint32_t)(			      \
        (((uint32_t)(x) & (uint32_t)0x000000ffUL) << 24) |            \
        (((uint32_t)(x) & (uint32_t)0x0000ff00UL) <<  8) |            \
        (((uint32_t)(x) & (uint32_t)0x000000ffUL) <<  8) |            \
        (((uint32_t)(x) & (uint32_t)0x0000ff00UL)      ) |            \
        (((uint32_t)(x) & (uint32_t)0xff000000UL) >> 24)))

__attribute__ ((noinline, noclone)) uint32_t
fake_swap32 (uint32_t in)
{
  return __fake_const_swab32 (in);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  uint32_t in = atoi(argv[1]);
  if (sizeof (uint32_t) * __CHAR_BIT__ != 32)
    return 0;
  if (fake_swap32 (in) != __fake_const_swab32(in))
    __builtin_abort ();
  return 0;
}

