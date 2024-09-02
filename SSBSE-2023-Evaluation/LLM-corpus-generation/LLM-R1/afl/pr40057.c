// Modification timestamp: 2023-08-14 15:05:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40057.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

__attribute__((noinline)) int
foo (unsigned long long x)
{
  unsigned long long y = (x >> 31ULL) & 1ULL;
  if (y == 0ULL)
    return 0;
  return -1;
}

__attribute__((noinline)) int
bar (long long x)
{
  long long y = (x >> 31LL) & 1LL;
  if (y == 0LL)
    return 0;
  return -1;
}

int
main (int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (sizeof (long long) != 8)
    return 0;
  if (foo (atoll(argv[1])))
    abort ();
  if (!foo (atoll(argv[2])))
    abort ();
  if (bar (atoll(argv[3])))
    abort ();
  if (!bar (atoll(argv[4])))
    abort ();
  return 0;
}


Please note that you need to provide 4 arguments when running the program: the first argument corresponds to `0x1682a9aaaULL`, the second argument corresponds to `0x1882a9aaaULL`, the third argument corresponds to `0x1682a9aaaLL`, and the fourth argument corresponds to `0x1882a9aaaLL`.