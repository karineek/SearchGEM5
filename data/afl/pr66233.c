// Modification timestamp: 2023-08-14 15:44:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr66233.c

#include <stdio.h>
#include <stdlib.h>

unsigned int v[8];

__attribute__((noinline, noclone)) void foo(unsigned int* v)
{
  int i;
  for (i = 0; i < 8; i++)
    v[i] = atoi(argv[i+1]);
}

int main(int argc, char *argv[]) {
  if (argc != 9) {
    printf("Usage: %s <value> <value> <value> <value> <value> <value> <value> <value>\n", argv[0]);
    return 1;
  }

  unsigned int i;
  foo(v);
  for (i = 0; i < 8; i++)
    if (v[i] != i)
      abort();
  return 0;
}

