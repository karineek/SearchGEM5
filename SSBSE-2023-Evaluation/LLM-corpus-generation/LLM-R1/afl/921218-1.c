// Modification timestamp: 2023-08-14 13:32:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921218-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned char f()
{
  return (unsigned char)("\377"[0]);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (f() != (unsigned char)(atoi(argv[1])))
    abort();
  exit(0);
}
