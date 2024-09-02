// Modification timestamp: 2023-08-14 17:27:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/block-byref-test.c

#include <stdio.h>
#include <stdlib.h>

#if defined(__BLOCKS__)
extern void abort();

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  __block unsigned char b1bool = 0;
  unsigned char *b1boolref = &b1bool;
  void (^b1)(void) = ^{
    if (b1bool != 1)
      abort();
  };
  *b1boolref = atoi(argv[1]);
  b1();

  __block unsigned char b2bool = 0;
  void (^b2)(void) = ^{
    if (b2bool != 1)
      abort();
  };
  unsigned char *b2boolref = &b2bool;
  *b2boolref = atoi(argv[2]);
  b2();

  return 0;
}
#else
int main(int argc, char* argv[]) {
  return 0;
}
#endif
