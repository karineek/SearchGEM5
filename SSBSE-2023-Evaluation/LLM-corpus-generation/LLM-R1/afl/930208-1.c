// Modification timestamp: 2023-08-14 13:32:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930208-1.c

#include <stdio.h>
#include <stdlib.h>

typedef union {
  long l;
  struct { char b3, b2, b1, b0; } c;
} T;

int f(T u)
{
  ++u.c.b0;
  ++u.c.b3;
  return (u.c.b1 != 2 || u.c.b2 != 2);
}

int main(int argc, char *argv[]) {
  T u;
  u.c.b1 = atoi(argv[1]);
  u.c.b2 = atoi(argv[2]);
  u.c.b0 = ~0;
  u.c.b3 = ~0;
  if (f(u))
    abort();
  exit(0);
}
