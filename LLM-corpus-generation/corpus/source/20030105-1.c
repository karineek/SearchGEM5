// Modification timestamp: 2023-08-14 12:41:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030105-1.c

#include <stdio.h>
#include <stdlib.h>

int __attribute__ ((noinline))
foo (const int *a, int size)
{
  int i, sum;

  sum = 0;
  for (i = 0; i < size; i++)
    sum += a[i];

  return sum;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  const int a[8] = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]) };
  int size = sizeof(a) / sizeof(*a);

  if (foo(a, size) != 28)
    abort ();

  exit (0);
}
