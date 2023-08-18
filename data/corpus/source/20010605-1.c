// Modification timestamp: 2023-08-14 11:59:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010605-1.c

#include <stdio.h>
#include <stdlib.h>

inline int fff(int x) {
  return x * 10;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int v = atoi(argv[1]);
  return (fff(v) != 420);
}
