
// Modification timestamp: 2023-08-04 14:35:02
// Original Source: http://barnyard.syr.edu/quickies/hanoi.c

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int A[4], B[4], C[4];

void Hanoi(int, int*, int*, int*);

void PrintAll()
{
   int i;

   printf("A: ");
   for(i=0;i<4;i++) printf(" %d ", A[i]);
   printf("\n");

   printf("B: ");
   for(i=0;i<4;i++) printf(" %d ", B[i]);
   printf("\n");

   printf("C: ");
   for(i=0;i<4;i++) printf(" %d ", C[i]);
   printf("\n");
   printf("------------------------------------------\n");
   return;
}

int Move(int *source, int *dest)
{
   int i = 0, j = 0;

   while (i < 4 && (source[i]) == 0) i++;
   while (j < 4 && (dest[j]) == 0) j++;

   dest[j-1] = source[i];
   source[i] = 0;
   PrintAll();
   return dest[j-1];
}

void Hanoi(int n, int *source, int *dest, int *spare)
{
   int i;
   if (n == 1) {
      Move(source, dest);
      return;
   }

   Hanoi(n-1, source, spare, dest);
   Move(source, dest);
   Hanoi(n-1, spare, dest, source);
   return;
}

int main(int argc, char *argv[])
{
   int i;

   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   for (i=0; i<4; i++) A[i] = atoi(argv[1]);
   for (i=0; i<4; i++) B[i] = 0;
   for (i=0; i<4; i++) C[i] = 0;

   printf("Solution of Tower of Hanoi Problem with %d Disks\n\n", atoi(argv[1]));

   printf("Starting state:\n");
   PrintAll();
   printf("\n\nSubsequent states:\n\n");

   Hanoi(4, A, B, C);

   return 0;
}
