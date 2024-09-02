// Modification timestamp: 2023-08-14 13:55:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990804-1.c

#include <stdio.h>
#include <stdlib.h>

int gfbyte(void) {
   return 0;
}

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int i, j, k;

   i = atoi(argv[1]);

   i = i + 1;

   if (i == 0)
      k = -0;
   else
      k = i + 0;

   if (i != 1)
      abort();

   k = 1;
   if (k <= i)
      do {
         j = gfbyte();
      } while (k++ < i);

   exit(0);
}
