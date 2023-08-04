
// Modification timestamp: 2023-08-04 14:38:33
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00192.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int Count = atoi(argv[1]);

   for (;;) {
      Count++;
      printf("%d\n", Count);
      if (Count >= 10)
         break;
   }

   return 0;
}
