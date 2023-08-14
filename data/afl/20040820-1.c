// Modification timestamp: 2023-08-14 12:58:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040820-1.c

#include <stdlib.h>

extern void exit (int);
extern void abort (void);

void check(int a) {
  if (a != 1)
    abort();
}

void test(int a, int b) {
  check((a ? atoi(argv[1]) : 0) | (b ? atoi(argv[2]) : 0));
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  test(atoi(argv[1]), atoi(argv[2]));
  exit(0);
}
