// Modification timestamp: 2023-08-04 13:55:54
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00068.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  return x;
}
