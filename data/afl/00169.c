
// Modification timestamp: 2023-08-04 14:30:06
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00169.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int x, y, z;

   for (x = atoi(argv[1]); x < 2; x++)
   {
      for (y = atoi(argv[2]); y < 3; y++)
      {
         for (z = atoi(argv[3]); z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   return 0;
}
