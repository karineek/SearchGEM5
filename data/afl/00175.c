// Modification timestamp: 2023-08-04 14:32:51
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00175.c

#include <stdio.h>
#include <stdlib.h>

void charfunc(char a)
{
   printf("char: %c\n", a);
}

void intfunc(int a)
{
   printf("int: %d\n", a);
}

void floatfunc(float a)
{
   printf("float: %f\n", a);
}

int main(int argc, char *argv[])
{
   if (argc != 10) {
       printf("Usage: %s <charfunc_a> <charfunc_b> <charfunc_c> <intfunc_a> <intfunc_b> <intfunc_c> <floatfunc_a> <floatfunc_b> <floatfunc_c>\n", argv[0]);
       return 1;
   }

   charfunc(argv[1][0]);
   charfunc(atoi(argv[2]));
   charfunc(atof(argv[3]));

   intfunc(argv[4][0]);
   intfunc(atoi(argv[5]));
   intfunc(atof(argv[6]));

   floatfunc(argv[7][0]);
   floatfunc(atoi(argv[8]));
   floatfunc(atof(argv[9]));

   /* printf("%c %d %f\n", 'a', 'b', 'c'); */
   /* printf("%c %d %f\n", 97, 98, 99); */
   /* printf("%c %d %f\n", 97.0, 98.0, 99.0); */

   char b = 97;
   char c = 97.0;

   printf("%d %d\n", b, c);

   int d = 'a';
   int e = 97.0;

   printf("%d %d\n", d, e);

   float f = 'a';
   float g = 97;

   printf("%f %f\n", f, g);

   return 0;
}

