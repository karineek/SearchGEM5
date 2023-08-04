
// Modification timestamp: 2023-08-04 14:39:17
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00195.c

#include <stdio.h>
#include <stdlib.h>

struct point
{
   double x;
   double y;
};

struct point point_array[100];

int main(int argc, char *argv[])
{
   int my_point;

   if (argc != 2) {
      printf("Usage: %s <index>\n", argv[0]);
      return 1;
   }

   my_point = atoi(argv[1]);

   point_array[my_point].x = 12.34;
   point_array[my_point].y = 56.78;

   printf("%f, %f\n", point_array[my_point].x, point_array[my_point].y);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
