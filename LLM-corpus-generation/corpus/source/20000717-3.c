
// Modification timestamp: 2023-08-10 16:39:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000717-3.c
#include <string.h>
#include <stdio.h>

#include <stdlib.h>

int c = -1;

foo (p)
     int *p;
{
  int x;
  int a;

  a = p[0];
  x = a + 5;
  a = c;
  p[0] = x - 15;
  return a;
}

int main(int argc, char *argv[])
{
   if (argc != 2) {
     printf("Usage: %s <value>\n", argv[0]);
     return 1;
   }

   int b = atoi(argv[1]);
   int a = foo(&b);

   if (a != -1 || b != (1 + 5 - 15))
     abort ();

   exit (0);
}
