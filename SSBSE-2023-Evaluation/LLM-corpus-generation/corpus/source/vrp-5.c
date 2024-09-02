// Modification timestamp: 2023-08-14 17:04:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vrp-5.c

#include <stdio.h>
#include <stdlib.h>

void test(unsigned int a, unsigned int b)
{
  if (a < 5)
    abort();
  if (b < 5)
    abort();
  if (a + b != 0U)
    abort();
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  unsigned int x = atoi(argv[1]);
  unsigned int y = atoi(argv[2]);
  
  test(x, y);
  exit (0);
}
