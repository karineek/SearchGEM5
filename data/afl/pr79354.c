// Modification timestamp: 2023-08-14 15:54:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79354.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int b, f, g;
float e;
unsigned long d;

__attribute__((noinline, noclone)) void foo(int *a) {
  for (g = 0; g < 32; g++) {
    if (f) {
      e = d;
      memcpy(&b, &e, sizeof(float));
      b = *a;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int h = atoi(argv[1]);
  f = 1;
  asm volatile("" : : : "memory");
  foo(&h);
  asm volatile("" : : : "memory");
  foo(&b);
  asm volatile("" : : : "memory");
  return 0;
}

