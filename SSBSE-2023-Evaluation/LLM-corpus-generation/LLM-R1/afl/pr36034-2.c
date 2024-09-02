// Modification timestamp: 2023-08-14 14:58:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36034-2.c

#include <stdio.h>
#include <stdlib.h>

double x[50] = { 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, 21, 22, 23, 24, 25, 26, -1, -1, -1, -1, 32, 33, 34, 35, 36, 37, -1, -1, -1, -1, 43, 44, 45, 46, 47, 48, -1, -1, -1, -1, 54, 55, 56, 57, 58, 59, -1, -1, -1, -1 };
double tmp[30];

void __attribute__((noinline)) test(int argc, char *argv[]) {
  int i, j;
  for (i = 0; i < 5; ++i) {
    tmp[i*6] = atoi(argv[i*10+1]);
    tmp[i*6+1] = atoi(argv[i*10+2]);
    tmp[i*6+2] = atoi(argv[i*10+3]);
    tmp[i*6+3] = atoi(argv[i*10+4]);
    tmp[i*6+4] = atoi(argv[i*10+5]);
    tmp[i*6+5] = atoi(argv[i*10+6]);
  }
}

extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 51) {
    printf("Usage: %s <value1> <value2> ... <value50>\n", argv[0]);
    return 1;
  }

  test(argc, argv);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (tmp[i*6+j] == -1) {
        abort();
      }
    }
  }

  return 0;
}

