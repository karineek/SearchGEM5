// Modification timestamp: 2023-08-14 12:06:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011114-1.c

#include <stdio.h>
#include <stdlib.h>

char foo(char bar[]) {
  return bar[1];
}

extern char foo(char *);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (foo(argv[1]) != 'y') {
    abort();
  }
  exit(0);
}
