
// Modification timestamp: 2023-08-04 14:38:33
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00192.c

#include <stdio.h>

int main() {
   int Count = 0;

   for (;;) {
      Count++;
      printf("%d\n", Count);
      if (Count >= 10)
         break;
   }

   return 0;
}
