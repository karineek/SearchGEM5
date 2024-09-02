// Modification timestamp: 2023-08-14 14:25:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/doloop-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void exit (int);
extern void abort (void);

volatile unsigned int i;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned char z = atoi(argv[1]);

  do ++i;
  while (--z > 0);

  if (i != UCHAR_MAX + 1U)
    abort ();
  
  exit (0);
}
