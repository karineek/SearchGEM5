
// Modification timestamp: 2023-08-04 14:27:47
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00161.c

#include <stdio.h>

int main() {
   int a;
   int p;
   int t;

   a = 1;
   p = 0;
   t = 0;

   do
   {
      printf("%d\n", a);
      t = a;
      a = t + p;
      p = t;
   } while (a < 100);

   return 0;
}
