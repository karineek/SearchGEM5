
// Modification timestamp: 2023-08-10 16:14:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/test/Programs/single-source/20000113-1.c

#include <stdlib.h>

struct x {
  unsigned x1:1;
  unsigned x2:2;
  unsigned x3:3;
};

void foobar (int x, int y, int z)
{
  struct x a = {x, y, z};
  struct x b = {x, y, z};
  struct x *c = &b;

  c->x3 += (a.x2 - a.x1) * c->x2;
  if (a.x1 != 1 || c->x3 != 5)
    abort ();
  exit (0);
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  int z = atoi(argv[3]);

  foobar (x, y, z);
  return 0;
}
