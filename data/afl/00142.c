
// Modification timestamp: 2023-08-04 14:23:13
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00142.c

#if defined(FOO)
int a;
#elif !defined(FOO) && defined(BAR)
int b;
#elif !defined(FOO) && !defined(BAR)
int c;
#else
int d;
#endif

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    c = atoi(argv[1]);
    return c;
}
