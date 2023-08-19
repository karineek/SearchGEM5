// Modification timestamp: 2023-08-04 14:29:42
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00167.c

#include <stdio.h>

int main() {
   int a = 1;

   if (a)
      printf("a is true\n");
   else
      printf("a is false\n");

   int b = 0;
   if (b)
      printf("b is true\n");
   else
      printf("b is false\n");

   return 0;
}

