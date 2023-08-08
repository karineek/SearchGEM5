// Modification timestamp: 2023-08-04 14:09:15
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00091.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int v;
  int sub[2];
} S;

S a[1];

int main(int argc, char *argv[]) {
  if (argc != 6) {
    printf("Usage: %s <a[0].v> <a[0].sub[0]> <a[0].sub[1]>\n", argv[0]);
    return 1;
  }

  a[0].v = atoi(argv[1]);
  a[0].sub[0] = atoi(argv[2]);
  a[0].sub[1] = atoi(argv[3]);

  if (a[0].v != atoi(argv[1]))
    return 1;
  if (a[0].sub[0] != atoi(argv[2]))
    return 2;
  if (a[0].sub[1] != atoi(argv[3]))
    return 3;

  return 0;
}
