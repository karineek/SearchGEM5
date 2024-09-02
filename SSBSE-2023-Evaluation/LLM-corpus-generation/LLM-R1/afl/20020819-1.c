// Modification timestamp: 2023-08-14 12:36:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020819-1.c

#include <stdio.h>
#include <stdlib.h>

int foo() {
  return 0;
}

int main(int argc, char *argv[]) {
  int i, j, k, ccp_bad = 0;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);

  for (i = 0; i < arg; i++) {
    for (j = 0; j < arg; j++) {
      if (foo()) {
        ccp_bad = 1;
      }
    }

    k = ccp_bad != 0;
    if (k) {
      abort();
    }
  }

  exit(0);
}

