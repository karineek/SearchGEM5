// Modification timestamp: 2023-08-14 15:04:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr39233.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

__attribute__((noinline)) void foo (void *p) {
  long l = (long) p;
  if (l < 0 || l > 6)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short i = atoi(argv[1]);
  for (i = 6; i >= 0; i--)
    foo((void *) (long) i);
  return 0;
}

In this case, the `main` function already takes command-line arguments, so I added the argument parsing code and utilized `atoi()` to convert the argument to a `short` integer before the loop.