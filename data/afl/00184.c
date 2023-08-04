
// Modification timestamp: 2023-08-04 14:36:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00184.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 3) {
      printf("Usage: %s <char> <short>\n", argv[0]);
      return 1;
   }

   char a = argv[1][0];
   short b = atoi(argv[2]);

   printf("%d %d\n", sizeof(char), sizeof(a));
   printf("%d %d\n", sizeof(short), sizeof(b));

   return 0;
}
