// Modification timestamp: 2023-08-04 13:57:57
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00074.c

#if defined X
X
#endif

#if defined(X)
X
#endif

#if X
X
#endif

#define X 0

#if X
X
#endif

#if defined(X)
int x = 0;
#endif

#undef X
#define X 1

#if X
int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    return atoi(argv[1]);
}
#endif
