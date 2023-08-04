
// Modification timestamp: 2023-08-04 14:30:57
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00171.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int a;
   int *b;
   int *c;

   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   a = atoi(argv[1]);
   b = &a;
   c = NULL;

   printf("%d\n", *b);

   if (b == NULL)
      printf("b is NULL\n");
   else
      printf("b is not NULL\n");

   if (c == NULL)
      printf("c is NULL\n");
   else
      printf("c is not NULL\n");

   return 0;
}
