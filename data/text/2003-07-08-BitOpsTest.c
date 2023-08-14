
// Modification timestamp: 2023-08-10 14:51:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/BitOps/2003-07-08-BitOpsTest.c

#include <stdio.h>

void test(int A, int B, int C, int D) {
  int bxor = A ^ B ^ C ^ D;
  int bor  = A | B | C | D;
  int band = A & B & C & D;
  int bandnot = (A & ~B) ^ (C & ~D);
  int bornot  = (A | ~B) ^ (C | ~D);

  printf("%d %d %d %d %d\n", bxor, bor, band, bandnot, bornot);
}

int main() {
  test(7, 8, -5, 5);
  return 0;
}