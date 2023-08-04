
// Modification timestamp: 2023-08-04 14:21:54
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00135.c

int main(void) {
    long long i;
    unsigned long long u;

    i = 1;
    i = -1;
    i = -1l;
    i = -1u;
    i = -1ll;
    i = -1ll & 3;
    i = -1ll < 0;

    u = 1;
    u = -1;
    u = -1l;
    u = -1u;
    u = -1ll;
    u = -1llu & 3;
    u = -1llu < 0;
    return 0;
}
