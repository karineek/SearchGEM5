// Modification timestamp: 2023-08-14 13:34:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930614-2.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i, j, k, l;
  float x[8][2][8][2];

  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  for (i = 0; i < 8; i++)
    for (j = i; j < 8; j++)
      for (k = 0; k < 2; k++)
        for (l = 0; l < 2; l++) {
          if ((i == j) && (k == l))
            x[i][k][j][l] = atof(argv[1]);
          else
            x[i][k][j][l] = atof(argv[2]);
          if (x[i][k][j][l] < 0.0)
            abort();
        }

  exit(0);
}


//In the above code, `atof` function is used to convert the command-line arguments to floating-point values. The value specified by the first argument is used for the assignment when the condition `(i == j) && (k == l)` is true, and the value specified by the second argument is used for the assignment when the condition is false.