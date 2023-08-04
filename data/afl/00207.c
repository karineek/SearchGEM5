
// Modification timestamp: 2023-08-04 14:52:17
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00207.c

#include <stdio.h>
#include <stdlib.h>

/* This test segfaults as of April 27, 2015. */
void f1(int argc)
{
  char test[argc];
  if(0)
  label:
    printf("boom!\n");
  if(argc-- == 0)
    return;
  goto label;
}

/* This segfaulted on 2015-11-19. */
void f2(void)
{
    goto start;
    {
        int a[1 && 1]; /* not a variable-length array */
        int b[1 || 1]; /* not a variable-length array */
        int c[1 ? 1 : 1]; /* not a variable-length array */
    start:
        a[0] = 0;
        b[0] = 0;
        c[0] = 0;
    }
}

void f3(void)
{
    printf("%d\n", 0 ? printf("x1\n") : 11);
    printf("%d\n", 1 ? 12 : printf("x2\n"));
    printf("%d\n", 0 && printf("x3\n"));
    printf("%d\n", 1 || printf("x4\n"));
}

int main(int argc, char *argv[])
{
    f1(argc);
    f2();
    f3();

    return 0;
}
