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

#define X argc

#if X
X
#endif

#if defined(X)
int x = atoi(argv[1]);
#endif

#undef X
#define X 1

#if X
int main(int argc, char *argv[]) {
    return 0;
}
#endif
