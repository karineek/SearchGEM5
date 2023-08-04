
// Modification timestamp: 2023-08-04 14:38:11
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00190.c

#include <stdio.h>

void fred(void)
{
   printf("yo\n");
}

int main()
{
   fred();

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
