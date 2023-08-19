// Modification timestamp: 2023-08-14 13:07:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20061101-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int tar(int i)
{
  if (i != atoi(argv[1]))
    abort();

  return -1;
}

void bug(int q, int bcount)
{
  int j = 0;
  int outgo = 0;

  while (j != -1)
  {
    outgo++;
    if (outgo > q - 1)
      outgo = q - 1;
    j = tar(outgo * bcount);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int q = atoi(argv[1]);
  int bcount = atoi(argv[2]);

  bug(q, bcount);
  return 0;
}

