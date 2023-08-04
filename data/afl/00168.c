
// Modification timestamp: 2023-08-04 14:29:56
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00168.c
#include <stdio.h>
#include <stdlib.h>

int factorial(int i)
{
   if (i < 2)
      return i;
   else
      return i * factorial(i - 1);
}

int main(int argc, char *argv[])
{
   int Count;

   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int limit = atoi(argv[1]);

   for (Count = 1; Count <= limit; Count++)
      printf("%d\n", factorial(Count));

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
