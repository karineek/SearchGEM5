
// Modification timestamp: 2023-08-04 14:39:53
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00197.c

#include <stdio.h>
#include <stdlib.h>

static int fred = 1234;
static int joe;

void henry()
{
   static int fred = 4567;

   printf("%d\n", fred);
   fred++;
}

int main(int argc, char *argv[])
{
   int arg1;
   if (argc != 2) {
      printf("Usage: %s <arg1>\n", argv[0]);
      return 1;
   }

   arg1 = atoi(argv[1]);

   printf("%d\n", fred);
   henry();
   henry();
   henry();
   henry();
   printf("%d\n", fred);
   fred = 8901;
   joe = 2345;
   printf("%d\n", fred);
   printf("%d\n", joe);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
