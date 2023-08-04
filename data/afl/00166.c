
// Modification timestamp: 2023-08-04 14:29:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00166.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 5) {
      printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
      return 1;
   }

   int a = atoi(argv[1]);
   int b = atoi(argv[2]);
   int c = atoi(argv[3]);
   int d = atoi(argv[4]);

   printf("%d\n", a);
   printf("%d\n", b);
   printf("%d\n", c);
   printf("%d\n", d);

   return 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
