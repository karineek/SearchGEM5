// Modification timestamp: 2023-08-14 11:54:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001203-1.c

#include <stdlib.h>

extern void exit(int);

static void foo(long a, char b[])
{
  struct {
    long a;
    char b[1];
  } x = { a, { b[0] } };
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  long tmp1 = atol(argv[1]);
  char tmp2 = argv[2][0];

  foo(tmp1, &tmp2);
  tmp = 1;
  exit(0);
}
