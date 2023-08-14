c
// Modification timestamp: 2023-08-10 15:50:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C++/Value.cpp

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

char a;
short b = 1, d = 5, h = 1;
char c[6];
int32_t e = 1, f = 20, g = 1, j = 1;
int32_t main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int32_t i = atoi(argv[1]);
  for (; f; f = a) {
    g = (5);
    for (; g <= 32; ++g) {
      i = 6;
      for (; i < -4; i++)
        while (7 > d)
          if (c[b]) {
            break;
          }
    L:
      if (j) {
        break;
      }
    }
  }
  e = 0;
  for (; e; e = 900) {
    d++;
    for (; h;)
      goto L;
  }
  printf("%" PRId32, e);
  return 0;
}
