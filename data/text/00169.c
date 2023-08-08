// Modification timestamp: 2023-08-04 14:30:06
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00169.c

#include <stdio.h>

int main() {
   int x, y, z;

   for (x = 0; x < 2; x++)
   {
      for (y = 0; y < 3; y++)
      {
         for (z = 0; z < 3; z++)
         {
            printf("%d %d %d\n", x, y, z);
         }
      }
   }

   return 0;
}
