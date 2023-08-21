// Modification timestamp: 2023-08-18 11:35:07
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-execs/00176.c
#include <stdlib.h>
#include <stdio.h>

int array[16];

//Swap integer values by array indexes
void swap(int a, int b)
{
   int tmp  = array[a];
   array[a] = array[b];
   array[b] = tmp;
}

//Partition the array into two halves and return the
//index about which the array is partitioned
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

//Quicksort the array
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
   if (argc != 17) {
      printf("Usage: %s <array[0]> <array[1]> ... <array[15]>\n", argv[0]);
      return 1;
   }

   for (int i = 0; i < 16; i++)
      array[i] = atoi(argv[i+1]);

   for (int i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   quicksort(0, 15);

   for (int i = 0; i < 16; i++)
      printf("%d ", array[i]);

   printf("\n");

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
