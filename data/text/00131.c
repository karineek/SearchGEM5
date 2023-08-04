
// Modification timestamp: 2023-08-04 14:20:45
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00131.c

#include <stdio.h>

int main() {
   printf("Hello\n");
   printf("Hello\n"); /* this is a comment */ printf("Hello\n");
   printf("Hello\n");
   // this is also a comment sayhello();
   printf("Hello\n");

   return 0;
}

