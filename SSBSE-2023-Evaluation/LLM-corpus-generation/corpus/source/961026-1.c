// Modification timestamp: 2023-08-14 13:47:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961026-1.c

#include <stdio.h>
#include <stdlib.h>

int test(int arg)
{
  if (arg > 0 || arg == 0)
    return 0;
  return -1;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);

  if (test(arg) != 0)
    abort();
  if (test(-1) != -1)
    abort();
  exit(0);
}
