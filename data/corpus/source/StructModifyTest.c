// Modification timestamp: 2023-08-14 17:27:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/StructModifyTest.c

#include <stdio.h>

typedef struct {
  int w;
  float x;
  double y;
  long long z;
} S1Ty;

typedef struct {
  S1Ty A, B;
} S2Ty;

extern int printf(const char *str, ...);
void printS1(S1Ty *V) {
  printf("%d, %f, %f, %lld\n", V->w, V->x, V->y, V->z);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S2Ty E;
  E.A.w = atoi(argv[1]);
  E.A.x = atof(argv[2]);
  E.A.y = atof(argv[3]);
  E.A.z = atoll(argv[4]);
  E.B.w = atoi(argv[5]);
  E.B.x = atof(argv[6]);
  E.B.y = atof(argv[7]);
  E.B.z = atoll(argv[8]);

  printS1(&E.A);
  printS1(&E.B);
  return 0;
}

//Note: This assumes that the command-line arguments passed to the program are in the correct order and have the correct types. Make sure to modify the arguments as needed to match the expected types.