// Modification timestamp: 2023-08-14 14:07:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bitfld-7.c

#include <stdio.h>
#include <stdlib.h>

union U
{
  const int a;
  unsigned b : 24;
};

static union U u = { 0x12345678 };

int main(int argc, char *argv[]) {
#ifdef __BYTE_ORDER__
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned y = atoi(argv[1]);
  return u.b - y;
#else
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned x = atoi(argv[1]);
  return u.b - x;
#endif
#endif
  return 0;
}
