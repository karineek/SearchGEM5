// Modification timestamp: 2023-08-14 12:37:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021118-1.c

#include <stdio.h>
#include <stdlib.h>

struct s {
  int f[4];
};

int foo(struct s s, int x1, int x2, int x3, int x4, int x5, int x6, int x7) {
  return s.f[3] + x7;
}

int main(int argc, char *argv[]) {
  if (argc != 9) {
    printf("Usage: %s <x1> <x2> <x3> <x4> <x5> <x6> <x7>\n", argv[0]);
    return 1;
  }

  struct s s = {1, 2, 3, 4};
  int x1 = atoi(argv[1]);
  int x2 = atoi(argv[2]);
  int x3 = atoi(argv[3]);
  int x4 = atoi(argv[4]);
  int x5 = atoi(argv[5]);
  int x6 = atoi(argv[6]);
  int x7 = atoi(argv[7]);

  if (foo(s, x1, x2, x3, x4, x5, x6, x7) != 704)
    abort();

  exit(0);
}
