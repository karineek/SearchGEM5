c
// Modification timestamp: 2023-08-04 14:33:35
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00177.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int x = atoi(argv[1]);
   printf("%d\n", x);
   printf("%d\n", x);
   printf("%d\n", x);
   printf("%d\n", x);
   printf("%d\n", x);
   printf("%d\n", x);
   printf("%d\n", x);
   printf("test %c\n", x);

   return 0;
}
