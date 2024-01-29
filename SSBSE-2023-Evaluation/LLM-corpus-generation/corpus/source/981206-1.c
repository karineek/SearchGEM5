// Modification timestamp: 2023-08-14 13:51:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/981206-1.c

#include <stdio.h>
#include <stdlib.h>

static unsigned short x, y;

void foo(unsigned short arg1, unsigned short arg2)
{
  x = arg1;
  y = arg2;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <arg1> <arg2>\n", argv[0]);
    return 1;
  }

  unsigned short arg1 = atoi(argv[1]);
  unsigned short arg2 = atoi(argv[2]);

  foo(arg1, arg2);

  if (x != arg1 || y != arg2)
    abort ();

  exit (0);
}
