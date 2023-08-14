// Modification timestamp: 2023-08-14 14:57:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34982.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

static void something(int i);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);
  something(arg);
  return 0;
}

static void something(int i) {
  if (i != -1)
    abort();
}
