// Modification timestamp: 2023-08-14 13:34:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930628-1.c

#include <stdio.h>
#include <stdlib.h>

void f(double x[2], double y[2]) {
  if (x == y)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  struct {
    int f[3];
    double x[1][2];
  } tp[4][2];
  int i, j, ki, kj, mi, mj;
  float bdm[4][2][4][2];

  for (i = 0; i < 4; i++)
    for (j = i; j < 4; j++)
      for (ki = 0; ki < 2; ki++)
        for (kj = 0; kj < 2; kj++)
          if ((j == i) && (ki == kj))
            bdm[i][ki][j][kj] = 1000.0;
          else {
            for (mi = 0; mi < 1; mi++)
              for (mj = 0; mj < 1; mj++)
                f(tp[i][ki].x[mi], tp[j][kj].x[mj]);
            bdm[i][ki][j][kj] = 1000.0;
          }
  exit(0);
}


//Note: Since the `f` function is called from `main`, I've added a prototype declaration for the `f` function before `main`.