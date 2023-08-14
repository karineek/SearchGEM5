// Modification timestamp: 2023-08-14 14:59:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36765.c

#include <stdio.h>
#include <stdlib.h>

int __attribute__((noinline))
foo(int i, int* p)
{
  *p = 0;
  p[i] = 1;
  return *p;
}

extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  int *p = malloc(4 * sizeof(int));
  
  if (foo(i, p) != 1)
    abort ();

  return 0;
}

