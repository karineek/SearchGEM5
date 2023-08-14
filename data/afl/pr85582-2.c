// Modification timestamp: 2023-08-14 16:01:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85582-2.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __SIZEOF_INT128__
typedef __int128 S;
typedef unsigned __int128 U;
#else
typedef long long S;
typedef unsigned long long U;
#endif

__attribute__((noipa)) S
f1 (S x, int y)
{
  x = x << (y & 5);
  x += y;
  return x;
}

__attribute__((noipa)) S
f2 (S x, int y)
{
  x = x >> (y & 5);
  x += y;
  return x;
}

__attribute__((noipa)) U
f3 (U x, int y)
{
  x = x >> (y & 5);
  x += y;
  return x;
}

int
main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S a = (S) atoi(argv[1]) << (sizeof (S) * __CHAR_BIT__ - 7);
  S b = f1 (a, atoi(argv[2]));
  if (b != ((S) 1 << (sizeof (S) * __CHAR_BIT__ - 3)) + atoi(argv[2]))
    __builtin_abort ();
  S c = (U) atoi(argv[3]) << (sizeof (S) * __CHAR_BIT__ - 1);
  S d = f2 (c, atoi(argv[4]));
  if ((U) d != ((U) 0x1f << (sizeof (S) * __CHAR_BIT__ - 5)) + atoi(argv[4]))
    __builtin_abort ();
  U e = (U) atoi(argv[5]) << (sizeof (U) * __CHAR_BIT__ - 1);
  U f = f3 (c, atoi(argv[6]));
  if (f != ((U) 1 << (sizeof (U) * __CHAR_BIT__ - 5)) + atoi(argv[6]))
    __builtin_abort ();
  return 0;
}
