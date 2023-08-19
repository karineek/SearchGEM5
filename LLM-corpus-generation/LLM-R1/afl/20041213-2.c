// Modification timestamp: 2023-08-14 13:00:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041213-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void) __attribute__((noreturn));
extern void exit(int) __attribute__((noreturn));

void __attribute__((noinline))
foo(int i, int next_n, int j)
{
  for (; i != 0; i--)
  {
    int n;

    for (n = next_n; j < n; j++)
      next_n++;

    if (j != n)
      abort();
  }
}

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <value> <next_n> <j>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  int next_n = atoi(argv[2]);
  int j = atoi(argv[3]);

  foo(i, next_n, j);

  exit(0);
}
