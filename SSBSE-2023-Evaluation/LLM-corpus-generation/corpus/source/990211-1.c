// Modification timestamp: 2023-08-14 13:52:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990211-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

#define N 77

void func(int i)
{
  if ((i < 0) && (i >= 0))
    abort();
  if ((i > 0) && (i <= 0))
    abort();
  if ((i >= 0) && (i < 0))
    abort();
  if ((i <= 0) && (i > 0))
    abort();

  if ((i < N) && (i >= N))
    abort();
  if ((i > N) && (i <= N))
    abort();
  if ((i >= N) && (i < N))
    abort();
  if ((i <= N) && (i > N))
    abort();

  if (! ((i < 0) || (i >= 0)))
    abort();
  if (! ((i > 0) || (i <= 0)))
    abort();
  if (! ((i >= 0) || (i < 0)))
    abort();
  if (! ((i <= 0) || (i > 0)))
    abort();

  if (! ((i < N) || (i >= N)))
    abort();
  if (! ((i > N) || (i <= N)))
    abort();
  if (! ((i >= N) || (i < N)))
    abort();
  if (! ((i <= N) || (i > N)))
    abort();

  return;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  func(i);
  return 0;
}
