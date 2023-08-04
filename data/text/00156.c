
// Modification timestamp: 2023-08-04 14:26:39
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00156.c

#include <stdio.h>

int main() {
   int Count;

   for (Count = 1; Count <= 10; Count++) {
      printf("%d\n", Count);
   }

   return 0;
}
