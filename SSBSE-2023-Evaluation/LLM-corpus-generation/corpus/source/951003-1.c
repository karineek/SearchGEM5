// Modification timestamp: 2023-08-14 13:43:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/951003-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int i) {
  return 12;
}

int g() {
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i, s;

  for (i = 0; i < 32; i++) {
    s = f(i);

    if (i == g())
      s = atoi(argv[1]);

    if (i == 0 || s == 12)
      ;
    else
      abort();
  }

  exit(0);
}
