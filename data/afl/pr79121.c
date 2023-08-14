// Modification timestamp: 2023-08-14 15:53:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79121.c

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern void abort(void);

__attribute__ ((noinline, noclone)) unsigned long long f1(uint32_t x) {
  return ((unsigned long long)x) << 4;
}

__attribute__ ((noinline, noclone)) long long f2(uint32_t x) {
  return ((long long)x) << 4;
}

__attribute__ ((noinline, noclone)) unsigned long long f3(uint32_t x) {
  return ((unsigned long long)x) << 4;
}

__attribute__ ((noinline, noclone)) long long f4(uint32_t x) {
  return ((long long)x) << 4;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  uint32_t x = atoi(argv[1]);
  uint32_t y = atoi(argv[2]);

  if (f1(x) != ((unsigned long long)y << 4)) {
    abort();
  }
  if (f2(x) != ((long long)y << 4)) {
    abort();
  }
  if (f3(x) != ((unsigned long long)y << 4)) {
    abort();
  }
  if (f4(x) != ((long long)y << 4)) {
    abort();
  }

  return 0;
}
