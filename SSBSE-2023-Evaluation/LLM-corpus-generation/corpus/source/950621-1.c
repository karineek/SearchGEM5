// Modification timestamp: 2023-08-14 13:42:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950621-1.c

#include <stdio.h>
#include <stdlib.h>

struct s {
  int a;
  int b;
  struct s *dummy;
};

int f(struct s *sp) {
  return sp && sp->a == -1 && sp->b == -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct s x;
  x.a = atoi(argv[1]);
  x.b = atoi(argv[2]);
  x.dummy = NULL;

  if (f(&x) == 0) {
    abort();
  }
  exit(0);
}
