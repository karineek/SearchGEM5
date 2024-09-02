// Modification timestamp: 2023-08-14 12:42:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030117-1.c

#include <stdio.h>
#include <stdlib.h>

int foo(int x, int y, int z);
int bar(int x, int y, int z);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  int z = atoi(argv[3]);

  if (foo(x, y, z) != 12)
    abort();

  if (bar(x, y, z) != 150)
    abort();

  exit(0);
}

int foo(int x, int y, int z) {
  return (x + y + z) / 3;
}

int bar(int x, int y, int z) {
  return foo(x * x, y * y, z * z);
}
