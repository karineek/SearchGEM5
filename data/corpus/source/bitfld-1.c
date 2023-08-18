// Modification timestamp: 2023-08-14 14:06:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bitfld-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

int main(int argc, char *argv[]) {
  struct x { signed int i : 7; unsigned int u : 7; } bit;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int u = atoi(argv[1]);
  int i = atoi(argv[2]);
  unsigned int unsigned_result = -13U % u;
  int signed_result = -13 % u;

  bit.u = u;
  bit.i = i;

  if (i % u != unsigned_result)
    abort ();
  if (i % (unsigned int) u != unsigned_result)
    abort ();

  if (i % bit.u != signed_result)
    abort ();

  if (bit.i % bit.u != signed_result)
    abort ();

  if (i % (unsigned int) bit.u != unsigned_result)
    abort ();

  if (bit.i % (unsigned int) bit.u != unsigned_result)
    abort ();

  return 0;
}
