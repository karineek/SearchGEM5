// Modification timestamp: 2023-08-14 16:54:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/unroll-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

inline int f(int x)
{
  return (x + 1);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);

  while ((f(f(f(f(f(f(f(f(f(f(1))))))))))) + a < 12)
  {
    a++;
    exit(0);
  }
  if (a != 1)
    abort();
}
