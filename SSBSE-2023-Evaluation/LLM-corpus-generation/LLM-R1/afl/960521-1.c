// Modification timestamp: 2023-08-14 13:46:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960521-1.c

#include <stdlib.h>

int *a, *b;
int n;

#ifdef STACK_SIZE
#define BLOCK_SIZE (STACK_SIZE / (sizeof (*a) + sizeof (*b)))
#else
#define BLOCK_SIZE 32768
#endif

void foo(int n) {
  int i;
  for (i = 0; i < n; i++)
    a[i] = -1;
  for (i = 0; i < BLOCK_SIZE - 1; i++)
    b[i] = -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  n = atoi(argv[1]);
  a = malloc(n * sizeof(*a));
  b = malloc(n * sizeof(*b));
  *b++ = 0;
  foo(n);
  if (b[-1])
    abort();
  exit(0);
}
