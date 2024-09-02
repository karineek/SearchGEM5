// Modification timestamp: 2023-08-14 13:21:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140326-1.c
#include <stdlib.h>

#include <stdio.h>

int a;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);

  char e[2] = { 0, 0 }, f = 0;
  if (arg == 131072)
    f = e[arg];
  return f;
}
