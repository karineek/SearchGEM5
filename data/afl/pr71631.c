// Modification timestamp: 2023-08-14 15:51:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71631.c

#include <stdio.h>
#include <stdlib.h>

volatile char v;
int a = 1, b = 1, c = 1;

void foo(const char *s)
{
  while (*s++)
    v = *s;
}

int main(int argc, char *argv[])
{
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }
  
  volatile int d = atoi(argv[1]);
  volatile int e = atoi(argv[2]);
  int f = 1 / a;
  int g = 1U < f;
  int h = 2 + g;
  int i = 3 % h;
  int j = e && b;
  int k = 1 == c;
  int l = d != 0;
  short m = (short)(-1 * i * l);
  short x = j * (k * m);
  if (i == 1)
    foo("AB");
  if (x != -1)
    __builtin_abort();
  return 0;
}
