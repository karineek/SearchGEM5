// Modification timestamp: 2023-08-14 11:54:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001130-1.c

#include <stdio.h>
#include <stdlib.h>

static inline int bar(void) { return atoi(argv[1]); }
static int mem[3];

static int foo(int x)
{
  if (x != 0)
    return x;

  mem[x++] = foo(bar());

  if (x != 1)
    abort();

  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  foo(atoi(argv[1]));
  return 0;
}
