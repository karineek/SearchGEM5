// Modification timestamp: 2023-08-02 17:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00005.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x;
  int *p;
  int **pp;

  x = atoi(argv[1]);
  p = &x;
  pp = &p;

  if (*p)
    return 1;
  if (**pp)
    return 1;
  else
    **pp = 1;

  if (x)
    return 0;
  else
    return 1;
}
