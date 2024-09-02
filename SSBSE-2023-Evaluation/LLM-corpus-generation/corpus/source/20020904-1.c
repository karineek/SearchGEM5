// Modification timestamp: 2023-08-14 12:36:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020904-1.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;

u8 fun(u8 y)
{
  u8 x = ((u8)255) / y;
  return x;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  u8 y = atoi(argv[1]);
  if (fun(y) != 127)
    abort ();
  return 0;
}
