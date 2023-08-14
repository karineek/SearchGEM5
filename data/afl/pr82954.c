// Modification timestamp: 2023-08-14 15:59:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr82954.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noipa)) void foo(int *__restrict p, int *__restrict q)
{
  p[0] = p[0] ^ 1;
  p[1] = p[1] ^ 2;
  p[2] = p[2] ^ q[2];
  p[3] = p[3] ^ q[3];
}

int main(int argc, char *argv[])
{
  if (argc != 5) {
    printf("Usage: %s <p0> <p1> <p2> <p3> <q0> <q1> <q2> <q3>\n", argv[0]);
    return 1;
  }

  int p[4] = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) };
  int q[4] = { atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]) };

  foo(p, q);

  if (p[0] != 17 || p[1] != 34 || p[2] != 66 || p[3] != 129)
    __builtin_abort();

  return 0;
}
