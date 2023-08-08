// Modification timestamp: 2023-08-04 13:56:32
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00071.c

#define X 1
#undef X

#ifdef X
FAIL
#endif

int main() {
    return 0;
}
