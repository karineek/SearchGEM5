// Modification timestamp: 2023-08-04 14:30:57
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00171.c

#include <stdio.h>

int main() {
   int a;
   int *b;
   int *c;

   a = 42;
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
