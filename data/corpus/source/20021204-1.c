// Modification timestamp: 2023-08-14 12:41:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021204-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);
extern void exit(int);

void foo(char *a, char *b) {
  if (strcmp(a, b) != 0)
    abort();
}

int z;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <str1> <str2>\n", argv[0]);
    return 1;
  }

  char *a = argv[1];
  char *b = argv[2];

  foo(z > 0 ? b - a : b - a - 1, b);
  exit(0);
}
