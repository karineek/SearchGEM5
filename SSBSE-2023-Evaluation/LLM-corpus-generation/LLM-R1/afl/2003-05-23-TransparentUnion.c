// Modification timestamp: 2023-08-14 17:32:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-23-TransparentUnion.c

#include <stdio.h>

typedef union {
  float *__fptr;
  int *__iptr;
} UNION __attribute__ ((__transparent_union__));

int try(UNION U) {
  return 1;
}
int test(int* argv1, float* argv2) {
  int I;
  float F;
  return try(argv1) | try(argv2);
}

int main(int argc, char *argv[]) {
  if (test((int*)argv[1], (float*)argv[2])) printf("ok");
  return 0;
}
