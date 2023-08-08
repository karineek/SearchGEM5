// Modification timestamp: 2023-08-04 14:51:52
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00206.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* must not affect how #pragma ppop_macro works */
    #define pop_macro foobar1

    /* must not affect how #pragma push_macro works */
    #define push_macro foobar2

    #undef abort
    #define abort argv[1]
    printf("abort = %s\n", abort);

    #pragma push_macro("abort")
    #undef abort
    #define abort argv[1]
    printf("abort = %s\n", abort);

    #pragma push_macro("abort")
    #undef abort
    #define abort argv[1]
    printf("abort = %s\n", abort);

    #pragma pop_macro("abort")
    printf("abort = %s\n", abort);

    #pragma pop_macro("abort")
    printf("abort = %s\n", abort);
}
