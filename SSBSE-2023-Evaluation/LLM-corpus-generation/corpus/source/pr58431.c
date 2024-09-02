// Modification timestamp: 2023-08-14 15:30:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58431.c

#include <stdio.h>
#include <stdlib.h>

char a, h;
int b, d = 0, e, g, j, k;
volatile int c;
short i;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int m;

  m = i ^= 1;
  for (b = 0; b < 1; b++) {
    char o = m;
    g = k;
    j = j || c;
    if (a != o)
      for (; d < 1; d++)
        ;
    else {
      char *p = &h;
      *p = atoi(argv[1]);
      for (; e; e++)
        ;
    }
  }

  if (h != 0)
    __builtin_abort();

  return 0;
}
