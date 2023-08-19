// Modification timestamp: 2023-08-14 12:49:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030928-1.c

#include <stdio.h>
#include <stdlib.h>

void get_addrs(const char **x, int *y)
{
  x[0] = argv[1] + (y[0] - 0x10000) * 2;
  x[1] = argv[2] + (y[1] - 0x20000) * 2;
  x[2] = argv[3] + (y[2] - 0x30000) * 2;
  x[3] = argv[4] + (y[3] - 0x40000) * 2;
  x[4] = argv[5] + (y[4] - 0x50000) * 2;
  x[5] = argv[6] + (y[5] - 0x60000) * 2;
  x[6] = argv[7] + (y[6] - 0x70000) * 2;
  x[7] = argv[8] + (y[7] - 0x80000) * 2;
}

int main(int argc, char *argv[])
{
  if (argc != 9)
  {
    printf("Usage: %s <x1> <x2> <x3> <x4> <x5> <x6> <x7> <x8>\n", argv[0]);
    return 1;
  }

  const char *x[8];
  int y[8];
  int i;

  for (i = 0; i < 8; i++)
    y[i] = 0x10000 * (i + 1);
  get_addrs(x, y);
  for (i = 0; i < 8; i++)
    if (*x[i] != 'a')
      abort();
  exit(0);
}
