// Modification timestamp: 2023-08-14 13:35:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930702-1.c

#include <stdio.h>
#include <stdlib.h>

void fp(double a, int b)
{
  if (a != atof(argv[1]) || b != atoi(argv[2]))
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int (*f) (double, int) = fp;

  fp(atof(argv[1]), atoi(argv[2]));
  f(atof(argv[1]), atoi(argv[2]));
  exit(0);
}
