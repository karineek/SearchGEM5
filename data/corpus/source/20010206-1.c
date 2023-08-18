// Modification timestamp: 2023-08-14 11:57:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010206-1.c

#include <stdio.h>
#include <stdlib.h>

int foo(void)
{
  int i;
#line 1 "20010206-1.c"
  if (0) i = 1; else i
#line 1 "20010206-1.c"
    = atoi(argv[1]);
  return i;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (foo() != atoi(argv[1]))
    abort();
  exit(0);
}
