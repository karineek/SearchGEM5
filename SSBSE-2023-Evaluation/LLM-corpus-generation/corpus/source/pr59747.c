// Modification timestamp: 2023-08-14 15:37:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59747.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
extern void exit (int);

int a[6], c = 1, d;
short e;

int __attribute__ ((noinline))
fn1 (int p)
{
  return a[p];
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (sizeof (long long) != 8)
    exit (0);

  a[0] = atoi(argv[1]);
  if (c)
    e--;
  d = e;
  long long f = e;
  if (fn1 ((f >> 56) & 1) != 0)
    abort ();
  exit (0);
}
