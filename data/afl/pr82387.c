// Modification timestamp: 2023-08-14 15:57:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr82387.c

#include <stdio.h>
#include <stdlib.h>

struct A { int b; };
int f = 1;

struct A
foo (int h_idx)
{
  struct A h[] = {
    {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1},
    {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1},
    {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1},
    {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1},
    {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1},
    {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1},
    {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1}, {1},
  };
  return h[h_idx];
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int h_idx = atoi(argv[1]);

  struct A i = foo(h_idx), j = i;
  j.b && (f = 0);
  return f;
}

