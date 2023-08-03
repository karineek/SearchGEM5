// Modification timestamp: 2023-08-02 16:50:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00004.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x;
  int *p;
  
  x = atoi(argv[1]);
  p = &x;
  *p = 0;

  return *p;
}
