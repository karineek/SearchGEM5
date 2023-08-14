
// Modification timestamp: 2023-08-10 14:51:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/BitOps/2003-07-08-BitOpsTest.c

#include <stdio.h>
#include <stdlib.h>

void test(int A, int B, int C, int D) {
  int bxor = A ^ B ^ C ^ D;
  int bor  = A | B | C | D;
  int band = A & B & C & D;
  int bandnot = (A & ~B) ^ (C & ~D);
  int bornot  = (A | ~B) ^ (C | ~D);

  printf("%d %d %d %d %d\n", bxor, bor, band, bandnot, bornot);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <A> <B> <C> <D>\n", argv[0]);
    return 1;
  }

  int A = atoi(argv[1]);
  int B = atoi(argv[2]);
  int C = atoi(argv[3]);
  int D = atoi(argv[4]);

  test(A, B, C, D);

  return 0;
}
