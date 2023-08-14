// Modification timestamp: 2023-08-14 12:11:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020321-1.c

#include <stdio.h>

float g (void *a, void *b, int e, int c, float d)
{
  return d;
}

float f (void *a, void *b, int c, float d)
{
  return g (a, b, 0, c, d);
}

int main (int argc, char *argv[])
{
  void *a = argv[1];
  void *b = argv[2];
  int c = atoi(argv[3]);
  float d = atof(argv[4]);

  f (a, b, c, d);
  return 0;
}
