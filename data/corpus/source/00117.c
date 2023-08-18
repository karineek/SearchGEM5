// Modification timestamp: 2023-08-04 14:13:13
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00117.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int x[] = { atoi(argv[1]), atoi(argv[2]) };
  return x[1];
}
