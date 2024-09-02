// Modification timestamp: 2023-08-14 14:07:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bitfld-6.c

#include <stdio.h>

union U
{
  const int a;
  unsigned b : 20;
};

static union U u = { 0x12345678 };

int main(int argc, char *argv[]) {
#ifdef __BYTE_ORDER__
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned value = atoi(argv[1]);
  return u.b - value;
#else
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned value = atoi(argv[1]);
  return u.b - value;
#endif
#endif
  return 0;
}
