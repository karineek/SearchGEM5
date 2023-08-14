// Modification timestamp: 2023-08-14 13:32:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930111-1.c

#include <stdio.h>
#include <stdlib.h>

int wwrite(long long i);

int main(int argc, char *argv[]) {
  if (wwrite((long long)atoi(argv[1])) != 123)
    abort();
  exit(0);
}

int wwrite(long long i)
{
  switch(i)
    {
    case 3:
    case 10:
    case 23:
    case 28:
    case 47:
      return 0;
    default:
      return 123;
    }
}
