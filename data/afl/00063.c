
// Modification timestamp: 2023-08-04 13:52:58
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00063.c

#define BAR 0
#ifdef BAR
    #ifdef FOO
        XXX
        #ifdef FOO
            XXX
        #endif
    #else
        #define FOO
        #ifdef FOO
            int x = BAR;
        #endif
    #endif
#endif

int main(int argc, char *argv[]) {
    return BAR;
}
