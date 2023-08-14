// Modification timestamp: 2023-08-14 14:42:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/packed-1.c

#include <stdio.h>
#include <stdlib.h>

short x1;

struct {
  short i __attribute__ ((packed));
} t;

void f() {
  t.i = x1;
  if (t.i != atoi(argv[1])) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  x1 = atoi(argv[1]);
  f();
  exit(0);
}
