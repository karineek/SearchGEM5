// Modification timestamp: 2023-08-14 16:54:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/usmul.c

#include <stdio.h>
#include <stdlib.h>

int __attribute__ ((noinline)) foo (short x, unsigned short y)
{
  return x * y;
}

int __attribute__ ((noinline)) bar (unsigned short x, short y)
{
  return x * y;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  short x = atoi(argv[1]);
  unsigned short y = atoi(argv[2]);

  if (foo (x, y) != -131070)
    abort ();
  if (foo (2, y) != 131070)
    abort ();
  if (foo (-32768, y) != -1073741824)
    abort ();
  if (foo (32767, y) != 1073709056)
    abort ();

  if (bar (y, x) != -131070)
    abort ();
  if (bar (y, 2) != 131070)
    abort ();
  if (bar (0x8000, -32768) != -1073741824)
    abort ();
  if (bar (0x8000, 32767) != 1073709056)
    abort ();

  exit (0);
}
