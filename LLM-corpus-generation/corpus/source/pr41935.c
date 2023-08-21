// Modification timestamp: 2023-08-14 15:08:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41935.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

long int
foo(int n, int i, int j)
{
  typedef int T[n];
  struct S {
    int a;
    T b[n];
  };
  return __builtin_offsetof(struct S, b[i][j]);
}

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <n> <i> <j>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int i = atoi(argv[2]);
  int j = atoi(argv[3]);

  typedef int T[5];
  struct S {
    int a;
    T b[5];
  };

  if (foo(n, i, j) != __builtin_offsetof(struct S, b) + (n * i + j) * sizeof(int))
  {
    abort();
  }

  return 0;
}
