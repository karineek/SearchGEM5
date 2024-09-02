// Modification timestamp: 2023-08-14 16:59:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-23.c

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

struct two { long x, y; };

void foo(int a, int b, int c, int d, int e, struct two f, int g, ...)
{
  va_list args;
  int h;

  va_start(args, g);
  h = va_arg(args, int);
  if (g != 1 || h != 2)
    abort ();
  va_end(args);
}

int main(int argc, char *argv[])
{
  struct two t = { 0, 0 };
  if (argc != 10) {
    printf("Usage: %s <value1> <value2> <value3> <value4> <value5> <value6> <value7> <value8> <value9>\n", argv[0]);
    return 1;
  }
  int a1 = atoi(argv[1]);
  int a2 = atoi(argv[2]);
  int a3 = atoi(argv[3]);
  int a4 = atoi(argv[4]);
  int a5 = atoi(argv[5]);
  int a6 = atoi(argv[6]);
  int a7 = atoi(argv[7]);
  int a8 = atoi(argv[8]);
  int a9 = atoi(argv[9]);
  foo(a1, a2, a3, a4, a5, t, a6, a7, a8, a9);
  return 0;
}
