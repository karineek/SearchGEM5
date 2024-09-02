// Modification timestamp: 2023-08-14 15:19:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr51023.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

short int foo(long int x) {
  return x;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long int a = atoi(argv[1]);
  if (foo(a) == a)
    abort();
  return 0;
}
