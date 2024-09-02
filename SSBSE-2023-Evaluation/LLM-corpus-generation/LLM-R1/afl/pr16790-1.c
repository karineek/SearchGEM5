// Modification timestamp: 2023-08-14 14:43:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr16790-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

static void test1(unsigned int u1)
{
  unsigned int y_final_1;
  signed short y_middle;
  unsigned int y_final_2;

  y_final_1 = (unsigned int)((signed short)(u1 * 2) * 3);
  y_middle = (signed short)(u1 * 2);
  y_final_2 = (unsigned int)(y_middle * 3);

  if (y_final_1 != y_final_2)
    abort();
}


static void test2(unsigned int u1)
{
  unsigned int y_final_1;
  signed short y_middle;
  unsigned int y_final_2;

  y_final_1 = (unsigned int)((signed short)(u1 << 1) * 3);
  y_middle = (signed short)(u1 << 1);
  y_final_2 = (unsigned int)(y_middle * 3);

  if (y_final_1 != y_final_2)
    abort();
}


int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int u1 = atoi(argv[1]);
  test1(u1);
  test2(u1);
  return 0;
}
