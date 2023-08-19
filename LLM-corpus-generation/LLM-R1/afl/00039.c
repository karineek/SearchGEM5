// Modification timestamp: 2023-08-04 13:40:03
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00039.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  void *p;
  int x;

  x = atoi(argv[1]);
  p = &x;

  if (*((int*)p) != 2)
    return 1;
  return 0;
}
