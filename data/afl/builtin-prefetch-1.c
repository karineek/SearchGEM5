// Modification timestamp: 2023-08-14 14:10:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-prefetch-1.c
#include <stdio.h>
#include <stdlib.h>

#define NO_TEMPORAL_LOCALITY 0
#define LOW_TEMPORAL_LOCALITY 1
#define MODERATE_TEMPORAL_LOCALITY 1
#define HIGH_TEMPORAL_LOCALITY 3

#define WRITE_ACCESS 1
#define READ_ACCESS 0

enum locality { none, low, moderate, high };
enum rw { read, write };

int arr[10];

void good_const(int *p)
{
  __builtin_prefetch(p, 0, 0);
  __builtin_prefetch(p, 0, 1);
  __builtin_prefetch(p, 0, 2);
  __builtin_prefetch(p, READ_ACCESS, 3);
  __builtin_prefetch(p, 1, NO_TEMPORAL_LOCALITY);
  __builtin_prefetch(p, 1, LOW_TEMPORAL_LOCALITY);
  __builtin_prefetch(p, 1, MODERATE_TEMPORAL_LOCALITY);
  __builtin_prefetch(p, WRITE_ACCESS, HIGH_TEMPORAL_LOCALITY);
}

void good_enum(int *p)
{
  __builtin_prefetch(p, read, none);
  __builtin_prefetch(p, read, low);
  __builtin_prefetch(p, read, moderate);
  __builtin_prefetch(p, read, high);
  __builtin_prefetch(p, write, none);
  __builtin_prefetch(p, write, low);
  __builtin_prefetch(p, write, moderate);
  __builtin_prefetch(p, write, high);
}

void good_expr(int *p)
{
  __builtin_prefetch(p, 1 - 1, 6 - (2 * 3));
  __builtin_prefetch(p, 1 + 0, 1 + 2);
}

void good_vararg(int *p)
{
  __builtin_prefetch(p, 0, 3);
  __builtin_prefetch(p, 0);
  __builtin_prefetch(p, 1);
  __builtin_prefetch(p);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  good_const(arr);
  good_enum(arr);
  good_expr(arr);
  good_vararg(arr);
  exit(x);
}