// Modification timestamp: 2023-08-04 13:56:15
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00070.c

#ifndef DEF
int x = 0;
#endif

#define DEF

#ifndef DEF
X
#endif

int main() {
    return x;
}
