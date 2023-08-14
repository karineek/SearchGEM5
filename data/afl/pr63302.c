// Modification timestamp: 2023-08-14 15:40:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr63302.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __SIZEOF_INT128__
#if __SIZEOF_INT128__ * __CHAR_BIT__ == 128
#define USE_INT128
#endif
#endif
#if __SIZEOF_LONG_LONG__ * __CHAR_BIT__ == 64
#define USE_LLONG
#endif

#ifdef USE_INT128
__attribute__((noinline, noclone)) int
foo (__int128 x)
{
  __int128 v = x & (((__int128) -1 << 63) | 0x7ff);

  return v == 0 || v == ((__int128) -1 << 63);
}
#endif

#ifdef USE_LLONG
__attribute__((noinline, noclone)) int
bar (long long x)
{
  long long v = x & (((long long) -1 << 31) | 0x7ff);

  return v == 0 || v == ((long long) -1 << 31);
}
#endif

int
main (int argc, char *argv[])
{
#ifdef USE_INT128
  if (foo (atoi(argv[1])) != 1
      || foo (atoi(argv[2])) != 0
      || foo (atoi(argv[3])) != 1
      || foo (atoi(argv[4])) != 0
      || foo ((__int128) 1 << 63) != 0
      || foo ((__int128) -1 << 63) != 1
      || foo (((__int128) -1 << 63) | 1) != 0
      || foo (((__int128) -1 << 63) | atoi(argv[5])) != 1
      || foo (((__int128) -1 << 63) | atoi(argv[6])) != 0)
    __builtin_abort ();
#endif
#ifdef USE_LLONG
  if (bar (atoi(argv[7])) != 1
      || bar (atoi(argv[8])) != 0
      || bar (atoi(argv[9])) != 1
      || bar (atoi(argv[10])) != 0
      || bar (1LL << 31) != 0
      || bar (-1LL << 31) != 1
      || bar ((-1LL << 31) | 1) != 0
      || bar ((-1LL << 31) | atoi(argv[11])) != 1
      || bar ((-1LL << 31) | atoi(argv[12])) != 0)
    __builtin_abort ();
#endif
  return 0;
}

