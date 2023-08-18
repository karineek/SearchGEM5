// Modification timestamp: 2023-08-14 15:26:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56837.c
// The modified code with args assignments would look like this:


#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
_Complex int a[1024];

__attribute__((noinline, noclone)) void
foo (void)
{
  int i;
  for (i = 0; i < 1024; i++)
    a[i] = -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  foo ();
  for (i = 0; i < 1024; i++)
    if (a[i] != atoi(argv[1]))
      abort ();
  return 0;
}
