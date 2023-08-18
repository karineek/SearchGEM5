// Modification timestamp: 2023-08-14 13:07:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20061101-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int tar(long i)
{
  if (i != atoi(argv[1]))
    abort();

  return -1;
}

void bug(int q, long bcount)
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
    printf("Usage: %s <q> <bcount>\n", argv[0]);
    return 1;
  }

  bug(atoi(argv[1]), atol(argv[2]));
  return 0;
}


//Note: The original code is modified to take command line arguments `q` and `bcount` and use them in the program logic.