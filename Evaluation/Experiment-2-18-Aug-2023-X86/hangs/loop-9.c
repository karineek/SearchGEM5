// Modification timestamp: 2023-08-14 14:32:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-9.c

#include <stdio.h>
#include <stdlib.h>

int false()
{
  return 0;
}

extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int count = 0;

  while (false() || count < atoi(argv[1]))
    ++count;

  if (count)
    abort();

  return 0;
}
