// Modification timestamp: 2023-08-14 15:57:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr81913.c

#include <stdio.h>
#include <stdlib.h>

typedef __UINT8_TYPE__ u8;
typedef __UINT32_TYPE__ u32;

static u32
b(u8 d, u32 e, u32 g)
{
  do
  {
    e += g + 1;
    d--;
  }
  while (d >= (u8)e);

  return e;
}

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <d> <e> <g>\n", argv[0]);
    return 1;
  }

  u8 d = atoi(argv[1]);
  u32 e = atoi(argv[2]);
  u32 g = atoi(argv[3]);

  u32 x = b(d, e, g);
  if (x != 0xd93190d0)
    __builtin_abort();
  return 0;
}
