
// Modification timestamp: 2023-08-04 14:36:11
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00183.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int Count;
   int arg = atoi(argv[1]);

   for (Count = 0; Count < arg; Count++)
   {
      printf("%d\n", (Count < 5) ? (Count*Count) : (Count * 3));
   }

   return 0;
}
