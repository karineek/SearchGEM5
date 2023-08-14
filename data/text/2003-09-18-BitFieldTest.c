
// Modification timestamp: 2023-08-10 15:08:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/McCat/08-main/cvt2a/2003-09-18-BitFieldTest.c

#include <stdio.h>

struct rtx_def {
  unsigned int jump : 1;
  unsigned int call : 1;
};

void i2(struct rtx_def *d) {
  d->jump = 0;
}

int main() {
  struct rtx_def D;
  D.call = 1;
  i2(&D);
  printf("%d %d\n", D.jump, D.call);
  return 0;
}
