// Modification timestamp: 2023-08-04 14:36:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00184.c

#include <stdio.h>

int main() {
   char a;
   short b;

   printf("%d %d\n", sizeof(char), sizeof(a));
   printf("%d %d\n", sizeof(short), sizeof(b));

   return 0;
}

