// Modification timestamp: 2023-08-14 12:50:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031020-1.c

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

void __attribute__((noinline))
foo (long x)
{
  if (x >= atoi(argv[1]))
    abort ();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  foo (atol(argv[2]));
  foo (atol(argv[3]));
  return 0;
}
