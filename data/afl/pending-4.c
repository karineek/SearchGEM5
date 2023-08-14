// Modification timestamp: 2023-08-14 14:42:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pending-4.c

#include <stdio.h>
#include <stdlib.h>

void dummy (int *x, int y) {}

int main(int argc, char *argv[]) {
  int number_columns = atoi(argv[1]);
  int cnt0 = 0;
  int cnt1 = 0;
  int i, A1;

  for (i = number_columns - 1; i != 0; i--) {
    if (i == 1) {
      dummy(&A1, i);
      cnt0++;
    } else {
      dummy(&A1, i - 1);
      cnt1++;
    }
  }
  if (cnt0 != 1 || cnt1 != 7)
    abort();
  exit(0);
}
