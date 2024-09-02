// Modification timestamp: 2023-08-14 16:02:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr86844.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noipa)) void
foo (int *p)
{
  *p = 0;
  *((char *)p + 3) = 1;
  *((char *)p + 1) = 2;
  *((char *)p + 2) = *((char *)p + 6);
}


int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  int a[2] = { -1, 0 };
  if (sizeof(int) != 4)
    return 0;
  ((char *)a)[6] = atoi(argv[4]);
  foo(a);
  if (((char *)a)[0] != atoi(argv[1]) || ((char *)a)[1] != atoi(argv[3]) ||
      ((char *)a)[2] != atoi(argv[4]) || ((char *)a)[3] != atoi(argv[2]))
    __builtin_abort();
  return 0;
}
