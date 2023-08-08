// Modification timestamp: 2023-08-04 14:27:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00159.c

#include <stdio.h>

int myfunc(int x)
{
   return x * x;
}

void vfunc(int a)
{
   printf("a=%d\n", a);
}

void qfunc()
{
   printf("qfunc()\n");
}

void zfunc()
{
   ((void (*)(void))0)();
}

int main()
{
   printf("%d\n", myfunc(3));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   return 0;
}

