// Modification timestamp: 2023-08-14 13:20:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120111-1.c
#include <stdio.h>

#include <stdlib.h>
#include <stdint.h>

uint32_t f0a (uint64_t arg2) __attribute__((noinline));

uint32_t
f0a (uint64_t arg)
{
  return ~((unsigned) (arg > -3));
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  uint32_t r1;
  uint64_t arg2 = atoi(argv[1]);
  r1 = f0a(arg2);
  if (r1 != ~0U)
    abort ();
  return 0;
}
