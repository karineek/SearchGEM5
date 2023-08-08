// Modification timestamp: 2023-08-04 14:28:35
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00163.c

#include <stdio.h>
#include <stdlib.h>

struct ziggy
{
   int a;
   int b;
   int c;
} bolshevic;

int main(int argc, char *argv[])
{
   int a;
   int *b;
   int c;

   if (argc != 2) {
       printf("Usage: %s <value>\n", argv[0]);
       return 1;
   }

   a = atoi(argv[1]);
   b = &a;
   printf("a = %d\n", *b);

   bolshevic.a = 12;
   bolshevic.b = 34;
   bolshevic.c = 56;

   printf("bolshevic.a = %d\n", bolshevic.a);
   printf("bolshevic.b = %d\n", bolshevic.b);
   printf("bolshevic.c = %d\n", bolshevic.c);

   struct ziggy *tsar = &bolshevic;

   printf("tsar->a = %d\n", tsar->a);
   printf("tsar->b = %d\n", tsar->b);
   printf("tsar->c = %d\n", tsar->c);

   b = &(bolshevic.b);
   printf("bolshevic.b = %d\n", *b);

   return 0;
}
