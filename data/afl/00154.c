
// Modification timestamp: 2023-08-04 14:26:21
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00154.c

#include <stdio.h>
#include <stdlib.h>

struct fred
{
   int boris;
   int natasha;
};

int main(int argc, char *argv[])
{
   if (argc != 2) {
       printf("Usage: %s <value>\n", argv[0]);
       return 1;
   }

   struct fred bloggs;

   bloggs.boris = atoi(argv[1]);
   bloggs.natasha = atoi(argv[2]);

   printf("%d\n", bloggs.boris);
   printf("%d\n", bloggs.natasha);

   struct fred jones[2];
   jones[0].boris = atoi(argv[3]);
   jones[0].natasha = atoi(argv[4]);
   jones[1].boris = atoi(argv[5]);
   jones[1].natasha = atoi(argv[6]);

   printf("%d\n", jones[0].boris);
   printf("%d\n", jones[0].natasha);
   printf("%d\n", jones[1].boris);
   printf("%d\n", jones[1].natasha);

   return 0;
}
