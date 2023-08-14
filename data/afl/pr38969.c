// Modification timestamp: 2023-08-14 15:03:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38969.c

#include <stdio.h>
#include <stdlib.h>

__complex__ float __attribute__((noinline)) foo(__complex__ float x) {
  return x;
}

__complex__ float __attribute__((noinline)) bar(__complex__ float x) {
  return foo(x);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <real_a> <imag_a> <real_b> <imag_b>\n", argv[0]);
    return 1;
  }

  __complex__ float a, b;
  __real__ a = atof(argv[1]);
  __imag__ a = atof(argv[2]);

  b = bar(a);

  if (__real__ a != atof(argv[3]) || __imag__ a != atof(argv[4])) {
    abort();
  }

  return 0;
}
