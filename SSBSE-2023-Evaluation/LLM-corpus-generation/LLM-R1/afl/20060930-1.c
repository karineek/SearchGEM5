// Modification timestamp: 2023-08-14 13:07:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060930-1.c

/* PR rtl-optimization/28096 */
/* Origin: Jan Stein <jan@gatespacetelematics.com> */

#include <stdio.h>
#include <stdlib.h>

int bar (int, int) __attribute__((noinline));
int bar (int a, int b)
{
  if (b != 1)
    abort ();
}

void foo(int, int) __attribute__((noinline));
void foo (int e, int n)
{
  int i, bb2, bb5;

  if (e > 0)
    e = -e;

  for (i = 0; i < n; i++)
    {
      if (e >= 0)
  {
    bb2 = 0;
    bb5 = 0;
  }
      else
  {
    bb5 = -e;
    bb2 = bb5;
  }

      bar (bb5, bb2);
    }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <e> <n>\n", argv[0]);
    return 1;
  }

  int e = atoi(argv[1]);
  int n = atoi(argv[2]);

  foo(e, n);

  return 0;
}
