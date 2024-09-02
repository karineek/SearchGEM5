// Modification timestamp: 2023-08-14 12:47:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030821-1.c

#include <stdio.h>

void abort(void);

int foo(int x) {
  if ((int)(x & 0x80ffffff) != (int)(0x8000fffe))
    abort();

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  return foo(x);
}
