
// Modification timestamp: 2023-08-04 14:40:34
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00199.c

#include <stdio.h>
#include <stdlib.h>

void fred()
{
   printf("In fred()\n");
   goto done;
   printf("In middle\n");
done:
   printf("At end\n");
}

void joe()
{
   int b = 5678;

   printf("In joe()\n");

   {
      int c;
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   c = atoi(argv[1]);
      printf("c = %d\n", c);
      goto outer;
      printf("uh-oh\n");
   }

outer:

   printf("done\n");
}

void henry()
{
   int a;

   printf("In henry()\n");
   goto inner;

   {
      int b;
inner:
      if (argc != 2) {
         printf("Usage: %s <value>\n", argv[0]);
         return 1;
      }

      b = atoi(argv[1]);
      printf("b = %d\n", b);
   }

   printf("done\n");
}

int main(int argc, char *argv[])
{
   fred();
   joe(argc, argv);
   henry(argc, argv);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
