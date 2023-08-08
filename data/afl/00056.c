// Modification timestamp: 2023-08-04 13:50:33
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00056.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 5) {
      printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
      return 1;
   }

   int a = atoi(argv[1]);
   printf("%d\n", a);

   int b = atoi(argv[2]);
   printf("%d\n", b);

   int c = atoi(argv[3]);
   int d = atoi(argv[4]);
   printf("%d, %d\n", c, d);

   return 0;
}
