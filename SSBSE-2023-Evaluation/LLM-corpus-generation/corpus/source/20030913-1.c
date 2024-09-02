// Modification timestamp: 2023-08-14 12:48:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030913-1.c

#include <stdio.h>
#include <stdlib.h>

int glob;

void fn2(int **q)
{
  *q = &glob;
}

void test(int *p)
{
  fn2(&p);

  *p = 42;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int p = atoi(argv[1]);
  test(&p);

  if (glob != 42) abort();
  exit(0);
}
