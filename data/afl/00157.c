
// Modification timestamp: 2023-08-04 14:26:50
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00157.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int Count;
   int Array[10];

   for (Count = 1; Count <= 10; Count++)
   {
      Array[Count-1] = Count * Count;
   }

   for (Count = 0; Count < 10; Count++)
   {
      printf("%d\n", Array[Count]);
   }

   return 0;
}
