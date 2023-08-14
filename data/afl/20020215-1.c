// Modification timestamp: 2023-08-14 12:10:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020215-1.c

#include <stdio.h>
#include <stdlib.h>

struct s
{
  short i1;
  long i2;
  short i3;
};

struct s foo (struct s s)
{
  s.i2++;
  return s;
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <i1> <i2> <i3>\n", argv[0]);
    return 1;
  }

  struct s s;
  s.i1 = atoi(argv[1]);
  s.i2 = atoi(argv[2]);
  s.i3 = atoi(argv[3]);

  s = foo(s);

  if (s.i1 != atoi(argv[1]) || s.i2 != atoi(argv[2]) + 1 || s.i3 != atoi(argv[3]))
    abort();

  return 0;
}
