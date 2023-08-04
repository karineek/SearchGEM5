
// Modification timestamp: 2023-08-04 14:11:52
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00108.c

#include <stdio.h>
#include <stdlib.h>

int foo(void);
int foo(void);
#define FOO argc

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int FOO = atoi(argv[1]);
  return FOO;
}
