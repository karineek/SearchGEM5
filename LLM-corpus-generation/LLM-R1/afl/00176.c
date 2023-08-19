// Modification timestamp: 2023-08-04 14:33:22
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00176.c

#include <stdio.h>
#include <stdlib.h>

int array[16];

void swap(int a, int b)
{
   int tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

int partition(int left, int right)
{
   int pivotIndex = left;
   int pivotValue = array[pivotIndex];
   int index = left;
   int i;

   swap(pivotIndex, right);
   for(i = left; i < right; i++)
   {
      if(array[i] < pivotValue)
      {
         swap(i, index);
         index += 1;
      }
   }
   swap(right, index);

   return index;
}

void quicksort(int left, int right)
{
   if(left >= right)
      return;

   int index = partition(left, right);
   quicksort(left, index - 1);
   quicksort(index + 1, right);
}

int main(int argc, char *argv[])
{
   int i;

   for (i = 0; i < argc - 1 && i < 16; i++)
      array[i] = atoi(argv[i + 1]);

   for (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   for (i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   return 0;
}
