// Modification timestamp: 2023-08-14 13:19:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20110418-1.c

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;

void f(uint64_t *a, uint64_t aa) __attribute__((noinline));
void f(uint64_t *a, uint64_t aa)
{
  uint64_t new_value = aa;
  uint64_t old_value = *a;
  int bit_size = 32;
    uint64_t mask = (uint64_t)(unsigned)(-1);
    uint64_t tmp = old_value & mask;
    new_value &= mask;
    /* On overflow we need to add 1 in the upper bits */
    if (tmp > new_value)
        new_value += 1ull<<bit_size;
    /* Add in the upper bits from the old value */
    new_value += old_value & ~mask;
    *a = new_value;
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <value> <new_value> <old_value>\n", argv[0]);
    return 1;
  }

  uint64_t value = strtoull(argv[1], NULL, 0);
  uint64_t new_value = strtoull(argv[2], NULL, 0);
  uint64_t old_value = strtoull(argv[3], NULL, 0);

  f(&value, new_value);
  if (value != old_value+1)
    abort();
  return 0;
}

