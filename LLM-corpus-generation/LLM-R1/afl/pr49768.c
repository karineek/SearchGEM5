// Modification timestamp: 2023-08-14 15:19:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49768.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  unsigned int unused : 1;
  unsigned int s : 1;
};

void abort(void) {
  printf("Aborted\n");
  exit(1);
}

int main(int argc, char *argv[]) {
  struct S s = { .s = atoi(argv[1]) };

  if (s.s != 1)
    abort();

  return 0;
}
