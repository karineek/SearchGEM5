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
int test() {
  int I;
  float F;
  return try(&I) | try(&F);
}

int main() {
  if (test()) printf("ok");
  return 0;
}
