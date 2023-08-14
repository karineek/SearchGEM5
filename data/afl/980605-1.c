// Modification timestamp: 2023-08-14 13:50:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980605-1.c



#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_SIZE
#define STACK_SIZE 200000
#endif

__inline__ static int
dummy(x)
{
  int y;
  y = (long)(x * 4711.3);
  return y;
}

int getval(int index, char *argv[]);

int f2(double x, int index, char *argv[])
{
  unsigned short s;
  int a, b, c, d, e, f, g, h, i, j;

  a = getval(index++, argv);
  b = getval(index++, argv);
  c = getval(index++, argv);
  d = getval(index++, argv);
  e = getval(index++, argv);
  f = getval(index++, argv);
  g = getval(index++, argv);
  h = getval(index++, argv);
  i = getval(index++, argv);
  j = getval(index++, argv);

  s = x;

  return a + b + c + d + e + f + g + h + i + j + s;
}

int x = 1;

int getval(int index, char *argv[])
{
  if (index >= argc) {
    printf("Invalid index\n");
    exit(1);
  }
  return atoi(argv[index]);
}

char buf[10];

void f(int argc, char *argv[])
{
  char ar[STACK_SIZE / 2];
  int a, b, c, d, e, f, g, h, i, j, k;

  int index = 1; // Start at index 1 to skip the program name in argv

  a = getval(index++, argv);
  b = getval(index++, argv);
  c = getval(index++, argv);
  d = getval(index++, argv);
  e = getval(index++, argv);
  f = getval(index++, argv);
  g = getval(index++, argv);
  h = getval(index++, argv);
  i = getval(index++, argv);
  j = getval(index++, argv);

  k = f2(17.0, index, argv);

  sprintf(buf, "%d\n", a + b + c + d + e + f + g + h + i + j + k);
  if (a + b + c + d + e + f + g + h + i + j + k != 227)
    abort();
}

int main(int argc, char *argv[])
{
  if (argc < 12) {
    printf("Insufficient number of arguments\n");
    exit(1);
  }

  f(argc, argv);
  exit(0);
}
