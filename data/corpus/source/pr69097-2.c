// Modification timestamp: 2023-08-14 15:48:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69097-2.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int
f1 (int x, int y)
{
  return x % y;
}

__attribute__((noinline, noclone)) int
f2 (int x, int y)
{
  return x % -y;
}

__attribute__((noinline, noclone)) int
f3 (int x, int y)
{
  int z = -y;
  return x % z;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (f1(atoi(argv[1]), 1) != 0 || f2(atoi(argv[2]), -1) != 0 || f3(atoi(argv[3]), -1) != 0) {
    printf("Error: Failed assertion\n");
    return 1;
  }
  
  return 0;
}
