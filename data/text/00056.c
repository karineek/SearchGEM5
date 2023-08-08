// Modification timestamp: 2023-08-04 13:50:33
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00056.c

#include <stdio.h>

int main() {
   int a;
   a = 42;
   printf("%d\n", a);

   int b = 64;
   printf("%d\n", b);

   int c = 12, d = 34;
   printf("%d, %d\n", c, d);

   return 0;
}
