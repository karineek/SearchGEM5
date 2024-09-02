// Modification timestamp: 2023-08-14 15:25:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr54471.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __SIZEOF_INT128__
#define T __int128
#else
#define T long long
#endif

extern void abort (void);

__attribute__ ((noinline))
unsigned T
foo (T ixi, unsigned ctr)
{
  if (argc != 2) {
    printf("Usage: %s <ixi> <ctr>\n", argv[0]);
    return 1;
  }

  unsigned T irslt = 1;
  T ix = ixi;

  for (; ctr; ctr--)
    {
      irslt *= ix;
      ix *= ix;
    }

  if (irslt != 14348907)
    abort ();
  return irslt;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <ixi> <ctr>\n", argv[0]);
    return 1;
  }

  unsigned T res;

  T ixi = atoi(argv[1]);
  unsigned ctr = atoi(argv[2]);

  res = foo (ixi, ctr);
  return 0;
}

Please note that the `main` function has been modified to accept command-line arguments `ixi` and `ctr` instead of using hardcoded values.