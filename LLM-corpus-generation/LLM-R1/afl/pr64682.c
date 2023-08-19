// Modification timestamp: 2023-08-14 15:41:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64682.c
/* PR rtl-optimization/64682 */

#include <stdio.h>
#include <stdlib.h>

int a, b = 1;

__attribute__((noinline, noclone)) void
foo (int x)
{
  if (x != 5)
    __builtin_abort ();
}

int
main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 0; i < atoi(argv[1]); i++)
    for (; a; a--)
      ;
  int *c = &b;
  if (*c)
    *c = 1 % (unsigned int) *c | 5;

  foo (b);

  return 0;
}