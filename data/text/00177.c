// Modification timestamp: 2023-08-04 14:33:35
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00177.c

#include <stdio.h>

int main() {
   printf("%d\n", '\1');
   printf("%d\n", '\10');
   printf("%d\n", '\100');
   printf("%d\n", '\x01');
   printf("%d\n", '\x0e');
   printf("%d\n", '\x10');
   printf("%d\n", '\x40');
   printf("test \x40\n");

   return 0;
}
