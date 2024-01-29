// Modification timestamp: 2023-08-14 14:30:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-2b.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a[2];

void f (int i)
{
  for (; i < INT_MAX; i++)
    {
      a[i] = -2;
      if (&a[i] == &a[1])
        break;
    }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  a[0] = a[1] = 0;
  f (atoi(argv[1]));
  if (a[0] != -2 || a[1] != -2)
    abort ();
  exit (0);
}
