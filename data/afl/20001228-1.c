// Modification timestamp: 2023-08-14 11:55:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001228-1.c

#include <stdio.h>
#include <stdlib.h>

int foo1(char *argv[])
{
  union {
    char a[sizeof(unsigned)];
    unsigned b;
  } u;

  u.b = atoi(argv[1]);
  return u.a[0];
}

int foo2(char *argv[])
{
  volatile union {
    char a[sizeof(unsigned)];
    unsigned b;
  } u;

  u.b = atoi(argv[1]);
  return u.a[0];
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (foo1(argv) != foo2(argv))
    abort ();

  exit (0);
}
