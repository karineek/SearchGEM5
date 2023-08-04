
// Modification timestamp: 2023-08-04 14:36:50
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00186.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   char Buf[100];
   int Count;
   int x = atoi(argv[1]);

   for (Count = 1; Count <= x; Count++) {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   return 0;
}
