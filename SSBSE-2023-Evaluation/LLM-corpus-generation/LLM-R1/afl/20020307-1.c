// Modification timestamp: 2023-08-14 12:11:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020307-1.c

#include <stdio.h>
#include <stdlib.h>

#define MASK(N) ((1UL << (N)) - 1)
#define BITS(N) ((1UL << ((N) - 1)) + 2)

#define FUNC(N) void f##N(long j) { if ((j & MASK(N)) >= BITS(N)) abort();}

FUNC(3)
FUNC(4)
FUNC(5)
FUNC(6)
FUNC(7)
FUNC(8)
FUNC(9)
FUNC(10)
FUNC(11)
FUNC(12)
FUNC(13)
FUNC(14)
FUNC(15)
FUNC(16)
FUNC(17)
FUNC(18)
FUNC(19)
FUNC(20)
FUNC(21)
FUNC(22)
FUNC(23)
FUNC(24)
FUNC(25)
FUNC(26)
FUNC(27)
FUNC(28)
FUNC(29)
FUNC(30)
FUNC(31)

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long argument = atol(argv[1]);
  f3(argument);
  f4(argument);
  f5(argument);
  f6(argument);
  f7(argument);
  f8(argument);
  f9(argument);
  f10(argument);
  f11(argument);
  f12(argument);
  f13(argument);
  f14(argument);
  f15(argument);
  f16(argument);
  f17(argument);
  f18(argument);
  f19(argument);
  f20(argument);
  f21(argument);
  f22(argument);
  f23(argument);
  f24(argument);
  f25(argument);
  f26(argument);
  f27(argument);
  f28(argument);
  f29(argument);
  f30(argument);
  f31(argument);

  exit(0);
}
