// Modification timestamp: 2023-08-14 15:51:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71700.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  signed f0 : 16;
  unsigned f1 : 1;
};

int b;
static struct S c[] = {{-1, 0}, {-1, 0}};
struct S d;

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S e = c[atoi(argv[1])];
  d = e;
  if (d.f1 != 0)
    abort();
  return 0;
}
