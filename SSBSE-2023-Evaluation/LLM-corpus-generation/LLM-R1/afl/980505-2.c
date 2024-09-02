// Modification timestamp: 2023-08-14 13:49:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980505-2.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short Uint16;
typedef unsigned int Uint;

Uint f(Uint16* values)
{
  Uint16 token;
  Uint count;

  token = values[0];
  count = token >> 8;

  return count;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  Uint16 arr[1] = { atoi(argv[1]) };
  if (f(arr) != 0x93)
    abort();

  exit(0);
}
