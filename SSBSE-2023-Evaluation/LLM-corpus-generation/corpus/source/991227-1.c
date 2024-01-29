// Modification timestamp: 2023-08-14 13:58:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991227-1.c

#include <stdio.h>
#include <stdlib.h>

char* doit(int flag) {
  return 1 + (flag ? "\0wrong\n" : "\0right\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <flag>\n", argv[0]);
    return 1;
  }

  int flag = atoi(argv[1]);
  char *result = doit(flag);
  if (*result == 'r' && result[1] == 'i')
    exit(0);
  abort();
}
