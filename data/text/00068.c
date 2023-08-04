
// Modification timestamp: 2023-08-04 13:55:54
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00068.c

#if 0
X
#elif 1
int x = 0;
#else
X
#endif

int main() {
    return x;
}
