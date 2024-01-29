// Modification timestamp: 2023-08-14 11:59:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010723-1.c

#include <stdio.h>
#include <stdlib.h>

int test() {
  int biv, giv;
  for (biv = 0, giv = 0; giv != atoi(argv[1]); biv++)
    giv = biv * atoi(argv[1]);
  return giv;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  if (test() != atoi(argv[1])) {
    abort();
  }
  
  exit(0);
}

