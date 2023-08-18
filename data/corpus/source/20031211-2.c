// Modification timestamp: 2023-08-14 12:50:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031211-2.c

#include <stdio.h>
#include <stdlib.h>

struct a
{
  unsigned int bitfield : 3;
};

void foo(unsigned int z)
{
  if (z != 3)
    abort();
}

int main(int argc, char *argv[]) {
  struct a a;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a.bitfield = atoi(argv[1]);
  foo(a.bitfield);
  exit(0);
}
