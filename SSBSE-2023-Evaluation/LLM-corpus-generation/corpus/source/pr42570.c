// Modification timestamp: 2023-08-14 15:09:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42570.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned char uint8_t;
uint8_t foo[1][0];

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  if (sizeof(foo) != x) {
    abort();
  }

  return 0;
}
