
// Modification timestamp: 2023-08-04 14:40:11
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00198.c

#include <stdio.h>
#include <stdlib.h>

enum fred { a, b, c };

int main(int argc, char *argv[]) {
   printf("a=%d\n", a);
   printf("b=%d\n", b);
   printf("c=%d\n", c);

   enum fred d;

   typedef enum { e, f, g } h;
   typedef enum { i, j, k } m;

   printf("e=%d\n", e);
   printf("f=%d\n", f);
   printf("g=%d\n", g);

   printf("i=%d\n", i);
   printf("j=%d\n", j);
   printf("k=%d\n", k);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
