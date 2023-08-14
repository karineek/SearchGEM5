// Modification timestamp: 2023-08-14 14:29:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ipa-sra-2.c

#include <stdio.h>
#include <stdlib.h>

struct big
{
  int data[1000000];
};

struct small
{
  int data[10];
};

union both
{
  struct big big;
  struct small small;
};

extern void *calloc (__SIZE_TYPE__, __SIZE_TYPE__);
extern void free (void *);

static int __attribute__((noinline))
foo (int fail, union both *agg)
{
  int r;
  if (fail)
    r = agg->big.data[999999];
  else
    r = agg->small.data[0];
  return r;
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  union both *agg = calloc (1, sizeof (struct small));
  int r;

  r = foo ((atoi(argv[1]) > 2000), agg);

  free (agg);
  return r;
}

