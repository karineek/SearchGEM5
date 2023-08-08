// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00167.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 3) {
      printf("Usage: %s <value1> <value2>\n", argv[0]);
      return 1;
   }

   int a = atoi(argv[1]);

   if (a)
      printf("a is true\n");
   else
      printf("a is false\n");

   int b = atoi(argv[2]);
   if (b)
      printf("b is true\n");
   else
      printf("b is false\n");

   return 0;
}
