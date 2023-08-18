// Modification timestamp: 2023-08-14 17:11:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-03-NotTest.c

#include <stdio.h>

void testBitWiseNot(int A, int B, int C, int D) {
  printf("Bitwise Not: %d %d %d %d\n", ~A, ~B, ~C, ~D);
}

void testBooleanNot(int A, int B, int C, int D) {
  printf("Boolean Not: %d %d %d %d %d %d\n",
         !(A > 0 && B > 0),
         !(A > 0 && C > 0),
         !(A > 0 && D > 0),
         !(B > 0 && C > 0),
         !(B > 0 && D > 0),
         !(C > 0 && D > 0));

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

  testBitWiseNot(A, B, C, D);
  testBooleanNot(A, B, C, D);
  
  return 0;
}

