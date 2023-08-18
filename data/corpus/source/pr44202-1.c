// Modification timestamp: 2023-08-14 15:12:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44202-1.c

#include <stdio.h>
#include <stdlib.h>

extern __attribute__ ((__noreturn__)) void exit(int);
extern __attribute__ ((__noreturn__)) void abort(void);
__attribute__ ((__noinline__))
int add512(int a, int *b)
{
  int c = a + 512;
  if (c != 0)
    *b = a;
  return c;
}

__attribute__ ((__noinline__))
int add513(int a, int *b)
{
  int c = a + 513;
  if (c == 0)
    *b = a;
  return c;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int b0 = -1;
  int b1 = -1;
  if (add512(-512, &b0) != 0 || b0 != -1 || add513(-513, &b1) != 0 || b1 != -513)
    abort ();
  exit (0);
}
