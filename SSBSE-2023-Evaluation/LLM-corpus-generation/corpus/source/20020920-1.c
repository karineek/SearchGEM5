// Modification timestamp: 2023-08-14 12:36:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020920-1.c

#include <stdio.h>
#include <stdlib.h>

struct B
{
  int x;
  int y;
};

struct A
{
  int z;
  struct B b;
};

struct A f (struct B b, int z)
{
  struct A a = { z, b };
  return a;
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <z> <b.x> <b.y>\n", argv[0]);
    return 1;
  }

  int z = atoi(argv[1]);
  int b_x = atoi(argv[2]);
  int b_y = atoi(argv[3]);

  struct B b = { b_x, b_y };
  struct A a = f(b, z);

  if (a.z != z || a.b.x != b_x || a.b.y != b_y) {
    abort();
  }

  exit(0);
}
