
// Modification timestamp: 2023-08-04 16:36:39
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/2002-05-03-NotTest.c

#include <stdio.h>
#include <stdlib.h>

void testBitWiseNot(int A, int B, int C, int D) {
  printf("Bitwise Not: %d %d %d %d\n", ~A, ~B, ~C, ~D);
}

void testBooleanNot(int A, int B, int C, int D) {
  printf("Boolean Not: %d %d %d %d %d %d\n",
         !((A > atoi(argv[1])) && (B > atoi(argv[1]))),
         !((A > atoi(argv[1])) && (C > atoi(argv[1]))),
         !((A > atoi(argv[1])) && (D > atoi(argv[1]))),
         !((B > atoi(argv[1])) && (C > atoi(argv[1]))),
         !((B > atoi(argv[1])) && (D > atoi(argv[1]))),
         !((C > atoi(argv[1])) && (D > atoi(argv[1]))));

}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  testBitWiseNot(1, 2, -3, 5);
  testBooleanNot(1, 2, -3, 5);
  return 0;
}
