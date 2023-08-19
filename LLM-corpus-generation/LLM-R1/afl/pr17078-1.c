// Modification timestamp: 2023-08-14 14:43:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr17078-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

void test(int *ptr)
{
  int i = atoi(ptr[1]);
  goto useless;
  if (0)
    {
      useless:
      i = 0;
    }
  else
    i = atoi(ptr[2]);
  *ptr = i;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int i = atoi(argv[1]);
  test(&i);
  if (i)
    abort ();
  return 0;
}
