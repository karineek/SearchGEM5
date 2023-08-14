// Modification timestamp: 2023-08-14 13:32:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921204-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned b0:1, f1:17, b18:1, b19:1, b20:1, f2:11;
} bf;

typedef union {
  bf b;
  unsigned w;
} bu;

bu f(bu i)
{
  bu o = i;

  if (o.b.b0)
    o.b.b18 = 1,
    o.b.b20 = 1;
  else
    o.b.b18 = 0,
    o.b.b20 = 0;

  return o;
}

int main(int argc, char *argv[]) {
  bu a;
  bu r;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a.w = atoi(argv[1]);
  a.b.b0 = 0;
  r = f(a);
  if (a.w != r.w)
    abort();
  exit(0);
}
