// Modification timestamp: 2023-08-14 15:39:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr62151.c

#include <stdio.h>
#include <stdlib.h>

int a, c, d, e, f, g, h, i;
short b;

int fn1() {
  int argc;
  char **argv;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int j[2];
  j[f] = 0;
  if (h)
    d = 0;
  else {
    for (; f; f++);
    for (a = 0; a < 1; a++)
      for (;;) {
        i = atoi(argv[1]) & ((atoi(argv[1]) ^ 1) & 83647) ? atoi(argv[1]) : atoi(argv[1]) - 1;
        g = 1 ? i : 0;
        e = j[0];
        if (c)
          break;
        return 0;
      }
  }
}

int main(int argc, char *argv[]) {
  fn1();
  if (g != -1)
    __builtin_abort();
  return 0;
}

