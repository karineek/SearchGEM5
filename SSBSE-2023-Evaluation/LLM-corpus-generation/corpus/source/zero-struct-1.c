// Modification timestamp: 2023-08-14 17:04:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/zero-struct-1.c

#include <stdio.h>
#include <stdlib.h>

struct g {};

char y[3];
char *f = &y[0];
char *ff = &y[0];

void h(char *f, char *ff) {
  struct g t;
  *((struct g *)(f++)) = *((struct g *)(ff++));
  *((struct g *)(f++)) = (struct g){};
  t = *((struct g *)(ff++));
}

void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  h(argv[1], argv[2]);
  if (f != &y[2])
    abort();
  if (ff != &y[2])
    abort();
  return 0;
}
