// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00159.c

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   int x = atoi(argv[1]);
   printf("%d\n", myfunc(x));
   printf("%d\n", myfunc(4));

   vfunc(1234);

   qfunc();

   return 0;
}
