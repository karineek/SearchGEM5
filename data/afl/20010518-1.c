// Modification timestamp: 2023-08-14 11:59:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010518-1.c

#include <stdio.h>
#include <stdlib.h>

int add(int a,
        int b,
        int c,
        int d,
        int e,
        int f,
        int g,
        int h,
        int i,
        int j,
        int k,
        int l,
        int m)
{
  return a + b + c + d + e + f + g + h + i + j + k + l + m;
}

int main(int argc, char *argv[]) {
  if (argc != 14) {
    printf("Usage: %s <arg1> <arg2> ... <arg13>\n", argv[0]);
    return 1;
  }

  int result = add(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]),
                   atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]),
                   atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]),
                   atoi(argv[13]));

  if (result != 91) {
    abort();
  }

  exit(0);
}
