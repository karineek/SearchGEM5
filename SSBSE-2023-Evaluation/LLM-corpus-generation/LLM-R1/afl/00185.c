// Modification timestamp: 2023-08-04 14:36:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00185.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int Count;

   int Array[10] = { argc, argc, argc, argc, argc, argc, argc, argc, argc, argc };

   for (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array[Count]);

   int Array2[10] = { argc, argc, argc, argc, argc, argc, argc, argc, argc, argc, };

   for (Count = 0; Count < 10; Count++)
      printf("%d: %d\n", Count, Array2[Count]);


   return 0;
}

