// Modification timestamp: 2023-08-04 14:38:01
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00189.c

#include <stdio.h>
#include <stdlib.h>

int fred(int p)
{
   printf("yo %d\n", p);
   return 42;
}

int (*f)(int) = &fred;

/* To test what this is supposed to test the destination function
   (fprint here) must not be called directly anywhere in the test.  */
int (*fprintfptr)(FILE *, const char *, ...) = &fprintf;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
  
    int x = atoi(argv[1]);
    fprintfptr(stdout, "%d\n", (*f)(x));

    return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
