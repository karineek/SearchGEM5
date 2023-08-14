// Modification timestamp: 2023-08-14 17:11:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-19-DivTest.c

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#include <inttypes.h>

extern int printf(const char *, ...);

void testL(int64_t Arg) {
  printf("%d\n", (int) (Arg / ((int64_t)1 << 4)));
  printf("%d\n", (int) (Arg / ((int64_t)1 << 46)));
}

void test(int Arg) {
  printf("%d\n", Arg / (1 << 0));
  printf("%d\n", Arg / (1 << 4));
  printf("%d\n", Arg / (1 << 18));
  printf("%d\n", Arg / (1 << 30));
}

int main() {
  int B20 = - (1 << 20);
  int64_t B53 = - ((int64_t)1 << 53);

  test(B20 + 32);
  test(B20 + 33);

  testL(B53 + 64);
  testL(B53 + 65);

  return 0;
}
