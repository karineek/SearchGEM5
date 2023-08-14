// Modification timestamp: 2023-08-14 14:28:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ifcvt-onecmpl-abs-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

__attribute__ ((noinline))
int foo(int n)
{
  if (n < 0)
    n = ~n;

  return n;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int result = foo(atoi(argv[1]));

  if (result != 0)
    abort ();

  return 0;
}
