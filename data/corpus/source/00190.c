// Modification timestamp: 2023-08-04 14:38:11
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00190.c

#include <stdio.h>
#include <stdlib.h>

void fred(void)
{
   printf("yo\n");
}

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   fred();

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
