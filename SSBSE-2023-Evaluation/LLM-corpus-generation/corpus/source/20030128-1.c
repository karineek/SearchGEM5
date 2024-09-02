// Modification timestamp: 2023-08-14 12:42:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030128-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned char x;
volatile short y;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <x> <y>\n", argv[0]);
    return 1;
  }

  x = atoi(argv[1]);
  y = atoi(argv[2]);
  
  x /= y;
  if (x != (unsigned char)-10)
    abort();
  exit(0);
}
