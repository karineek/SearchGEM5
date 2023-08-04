
// Modification timestamp: 2023-08-04 14:36:50
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00186.c

#include <stdio.h>

int main() {
   char Buf[100];
   int Count;

   for (Count = 1; Count <= 20; Count++) {
      sprintf(Buf, "->%02d<-\n", Count);
      printf("%s", Buf);
   }

   return 0;
}
