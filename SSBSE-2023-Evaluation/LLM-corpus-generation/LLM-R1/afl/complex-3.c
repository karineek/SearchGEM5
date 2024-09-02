// Modification timestamp: 2023-08-14 14:18:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-3.c

#include <stdio.h>
#include <stdlib.h>

struct complex
{
  float r;
  float i;
};

struct complex cmplx(float, float);

struct complex f(float a, float b)
{
  struct complex c;
  c.r = a;
  c.i = b;
  return c;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct complex z = f(atof(argv[1]), atof(argv[2]));
  
  if (z.r != atof(argv[1]) || z.i != atof(argv[2]))
    abort();
  
  exit(0);
}
