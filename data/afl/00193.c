
// Modification timestamp: 2023-08-04 14:38:48
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00193.c

#include <stdio.h>
#include <stdlib.h>

void fred(int x)
{
   switch (x)
   {
      case 1: printf("1\n"); return;
      case 2: printf("2\n"); break;
      case 3: printf("3\n"); return;
   }

   printf("out\n");
}

int main(int argc, char *argv[])
{
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int x = atoi(argv[1]);
   fred(x);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
