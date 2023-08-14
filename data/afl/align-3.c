// Modification timestamp: 2023-08-14 13:59:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/align-3.c

#include <stdio.h>
#include <stdlib.h>

void func(void) __attribute__((aligned(256)));

void func(void)
{
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (__alignof__(func) != atoi(argv[1]))
    abort();
  
  return 0;
}
