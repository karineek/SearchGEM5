// Modification timestamp: 2023-08-04 14:27:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00158.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int Count;

   for (Count = atoi(argv[1]); Count < 4; Count++)
   {
      printf("%d\n", Count);
      switch (Count)
      {
         case 1:
            printf("%d\n", 1);
            break;

         case 2:
            printf("%d\n", 2);
            break;

         default:
            printf("%d\n", 0);
            break;
      }
   }

   return 0;
}
