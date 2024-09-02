// Modification timestamp: 2023-08-14 13:51:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990106-1.c

#include <stdio.h>
#include <stdlib.h>

int foo(char *bufp) {
  int x = atoi(bufp);
  return (*bufp++ = x ? 'a' : 'b');
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char x = 0;
  if (foo(argv[1]) != 'a')
    abort();

  exit(0);
}
