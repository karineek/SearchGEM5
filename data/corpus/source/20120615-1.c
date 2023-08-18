// Modification timestamp: 2023-08-14 13:20:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120615-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

void __attribute__((noinline, noclone))
test1(int i)
{
  if (i == atoi(argv[1]))
    return;
  if (i != atoi(argv[2]))
  {
    if (i == atoi(argv[3]))
      return;
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }
  
  test1(atoi(argv[1]));
  return 0;
}
