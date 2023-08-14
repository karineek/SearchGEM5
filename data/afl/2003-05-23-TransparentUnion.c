
// Modification timestamp: 2023-08-10 15:54:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/TransparentUnion.c

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
  return try((UNION)&I) | try((UNION)&F);
}

int main() {
  if (test()) printf("ok");
  return 0;
}
