// Modification timestamp: 2023-08-04 14:27:34
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00160.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int a;
   int p;
   int t;

   a = 1;
   p = 0;
   t = 0;

   while (a < 100)
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   }

   if (argc != 2)
   {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   a = atoi(argv[1]);

   return 0;
}
