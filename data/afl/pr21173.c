// Modification timestamp: 2023-08-14 14:45:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr21173.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

char q;
void *a[2];

void foo(char *p) {
  int i;
  for (i = 0; i < 2; i++)
    a[i] += p - &q;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  foo(argv[1]);
  for (i = 0; i < 2; i++)
    if (a[i])
      abort();
  return 0;
}
