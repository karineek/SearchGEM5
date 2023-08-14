// Modification timestamp: 2023-08-14 15:51:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr77766.c

#include <stdio.h>

char a;
short b, d = 5, h;
char c[1];
int e, f = 4, g, j;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;

  // Initialize variables
  for (; f; f = a) {
    g = atoi(argv[1]);

    for (; g <= 32; ++g) {
      i = 0;

      for (; i < 3; i++) {
        while (1 > d) {
          if (c[b]) {
            break;
          }
        }

      L:
        if (j) {
          break;
        }
      }
    }
  }

  e = 0;
  for (; e; e = 0) {
    d++;
    for (; h;) {
      goto L;
    }
  }

  return 0;
}
