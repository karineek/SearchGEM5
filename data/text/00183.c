
// Modification timestamp: 2023-08-04 14:36:11
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00183.c

#include <stdio.h>

int main() {
   int Count;

   for (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", (Count < 5) ? (Count*Count) : (Count * 3));
   }

   return 0;
}

