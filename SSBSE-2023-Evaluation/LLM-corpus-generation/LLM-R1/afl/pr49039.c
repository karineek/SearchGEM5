// Modification timestamp: 2023-08-14 15:17:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49039.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
int cnt;

__attribute__((noinline, noclone)) void foo(unsigned int x, unsigned int y) {
  unsigned int minv, maxv;
  if (x == atoi(argv[1]) || y == atoi(argv[2])) {
    return;
  }
  minv = x < y ? x : y;
  maxv = x > y ? x : y;
  if (minv == atoi(argv[3])) {
    ++cnt;
  }
  if (maxv == atoi(argv[4])) {
    ++cnt;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
    return 1;
  }

  foo(atoi(argv[1]), atoi(argv[2]));
  if (cnt != 2) {
    abort();
  }
  return 0;
}
