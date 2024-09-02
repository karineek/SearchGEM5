// Modification timestamp: 2023-08-14 14:59:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36343.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = 0.0;
}

float __attribute__((noinline))
foo (int b, float f)
{
  int *i = 0;
  int **p;
  if (b)
    p = &i;
  else
    p = (int **)&f;
  bar (p);
  if (b)
    return **p;
  return f;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int b = atoi(argv[1]);
  float f = 1.0;
  if (foo(b, f) != 0.0)
    abort ();
  return 0;
}
