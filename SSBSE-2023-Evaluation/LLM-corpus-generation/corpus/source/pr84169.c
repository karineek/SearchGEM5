// Modification timestamp: 2023-08-14 15:59:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr84169.c

#ifdef __SIZEOF_INT128__
typedef unsigned __int128 T;
#else
typedef unsigned long long T;
#endif

#include <stdio.h>
#include <stdlib.h>

T b;

static __attribute__ ((noipa)) T
foo (T c, T d, T e, T f, T g, T h)
{
  __builtin_mul_overflow ((unsigned char) h, -16, &h);
  return b + h;
}

int
main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  T x = foo (0, 0, 0, 0, 0, atoi(argv[1]));
  if (x != -64)
    __builtin_abort ();
  return 0;
}
