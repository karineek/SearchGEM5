// Modification timestamp: 2023-08-14 15:26:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56799.c

#include <stdio.h>
#include <stdlib.h>

typedef struct { int x; int y; } S;
extern int foo(S*);

int hi = 0, lo = 0;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S a;
  int r;

  a.x = (int)atoi(argv[1]);
  a.y = atoi(argv[2]);

  r = foo(&a);

  if (r == 2 && lo == 0 && hi == 1) {
    exit(0);
  }
  abort();
}

typedef unsigned short u16;

__attribute__ ((noinline)) int foo(S* ptr) {
  int a = ptr->x;
  int c = 0;
  u16 b = (u16)a;

  if (b != 0) {
    lo = 1;
    c += ptr->y;
  }

  b = a >> 16;

  if (b != 0) {
    hi = 1;
    c += ptr->y;
  }

  c += ptr->y;
  return c;
}
