// Modification timestamp: 2023-08-14 13:31:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921123-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned short b0, b1, b2, b3;
} four_quarters;

four_quarters x;
int a, b;

void f(four_quarters j) {
  b = j.b2;
  a = j.b3;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  four_quarters x;
  x.b0 = x.b1 = x.b2 = 0;
  x.b3 = atoi(argv[1]);
  f(x);
  if (a != atoi(argv[1]))
    abort();
  exit(0);
}
