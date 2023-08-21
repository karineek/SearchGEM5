// Modification timestamp: 2023-08-14 12:48:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030916-1.c

#include <stdio.h>
#include <stdlib.h>

#if CHAR_BIT == 8

void f(unsigned int *x, unsigned char i)
{
  int j;

  i = 0x10;
  for (j = 0; j < 0x10; j++)
  {
    i += 0xe8;
    x[i] = 0;
    i -= 0xe7;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int x[256];
  int i;

  for (i = 0; i < 256; i++)
    x[i] = 1;

  unsigned char arg_i = atoi(argv[1]);
  f(x, arg_i);

  for (i = 0; i < 256; i++)
    if (x[i] != (i >= 0x08 && i < 0xf8))
      abort();

  return 0;
}
#else
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned char i = atoi(argv[1]);
  exit(0);
}
#endif
