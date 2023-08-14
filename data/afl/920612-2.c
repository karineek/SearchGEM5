// Modification timestamp: 2023-08-14 13:28:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920612-2.c

#include <stdio.h>
#include <stdlib.h>

int a(int x)
{
  while (x)
    i++, x--;
  return x;
}

int main(int argc, char *argv[]) {
  if (a(2) != 0)
    abort();

  exit(0);
}
