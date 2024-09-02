// Modification timestamp: 2023-08-14 15:47:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68390.c

#include <stdio.h>
#include <stdarg.h>

__attribute__ ((noinline))
double direct(int x, ...)
{
  return x * x;
}

__attribute__ ((noinline))
double broken(double (*indirect)(int x, ...), int v)
{
  va_list args;
  va_start(args, v);
  int x = va_arg(args, int);
  va_end(args);
  return indirect(x);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int i = atoi(argv[1]);
  double d1, d2;
  d1 = broken(direct, i);
  if (d1 != i * i)
  {
    printf("Test failed\n");
    return 1;
  }
  printf("Test passed\n");
  return 0;
}
