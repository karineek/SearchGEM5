// Modification timestamp: 2023-08-14 13:47:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961122-1.c

#include <stdio.h>
#include <stdlib.h>

long long acc;

void addhi(short a)
{
  acc += (long long) a << 32;
}

void subhi(short a)
{
  acc -= (long long) a << 32;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  acc = strtoll(argv[1], NULL, 0);

  addhi(1);
  if (acc != 0x1000000000000ll)
    abort();
  
  subhi(1);
  if (acc != 0xffff00000000ll)
    abort();
  
  exit(0);
}
