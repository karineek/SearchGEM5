// Modification timestamp: 2023-08-14 14:54:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33382.c

#include <stdio.h>
#include <stdlib.h>

struct Foo {
  int i;
  int j[];
};

struct Foo x = { 1, { 2, 0, 2, 3 } };

int foo(int *j)
{
  j[0] = 1;
  return j[1];
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int j[] = {atoi(argv[1]), 0, 2, 3};
  if (foo(j) != 0)
    abort();
  return 0;
}
