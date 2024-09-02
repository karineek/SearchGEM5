// Modification timestamp: 2023-08-14 14:30:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-14.c

#include <stdio.h>
#include <stdlib.h>

void f(int *a) {
  int i;

  for (i = atoi(argv[3]); --i;) {
    a[i] = 42 / i;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  int a3[3];
  f(a3);

  if (a3[1] != atoi(argv[1]) || a3[2] != atoi(argv[2])) {
    abort();
  }

  exit(0);
}
