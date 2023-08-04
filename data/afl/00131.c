
// Modification timestamp: 2023-08-04 14:20:45
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00131.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   printf("Hello\n");
   printf("Hello\n"); /* this is a comment */ printf("Hello\n");
   printf("Hello\n");
   // this is also a comment sayhello();
   printf("Hello\n");

   return 0;
}
