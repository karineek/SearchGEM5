// Modification timestamp: 2023-08-14 15:45:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr67714.c

#include <stdio.h>
#include <stdlib.h>

unsigned int b;
int c;

signed char fn1 (unsigned int b)
{
  signed char d;
  for (int i = 0; i < 1; i++)
    d = -15;
  return d;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  unsigned int b = atoi(argv[1]);
  
  for (c = 0; c < 1; c++)
    b = 0;
  char e = fn1(b);
  signed char f = e ^ b;
  volatile int g = (int) f;

  if (g != -15)
    __builtin_abort ();

  return 0;
}
