// Modification timestamp: 2023-08-14 14:49:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr24716.c

#include <stdio.h>
#include <stdlib.h>

int Link[] = { -1 };
int W[] = { 2 };

void abort(void) {
  printf("Aborted\n");
  exit(1);
}

int f(int k, int p) {
  int pdest, j, D1361;
  j = 0;
  pdest = 0;
  for (;;) {
    if (pdest > 2) {
      do {
        j--, pdest++;
      } while (j > 2);
    }

    if (j == 1)
      break;
    
    while (pdest > p) {
      if (j == p)
        pdest++;
    }

    do {
      D1361 = W[k];
      do {
        if (D1361 != 0)
          pdest = 1, W[k] = D1361 = 0;
      } while (p < 1);
    } while (k > 0);

    do {
      p = 0;
      k = Link[k];
      while (p < j) {
        if (k != -1)
          pdest++, p++;
      }
    } while (k != -1);
    j = 1;
  }

  return pdest;
}

int main(int argc, char *argv[]) {
  if (!f(atoi(argv[1]), atoi(argv[2])))
    abort();
  return 0;
}
