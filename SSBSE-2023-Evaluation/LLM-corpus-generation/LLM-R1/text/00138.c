// Modification timestamp: 2023-08-04 14:22:28
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00138.c

#define M(x) x
#define A(a,b) a(b)

int main(void) {
    char *a = A(M,"hi");

    return (a[1] == 'i') ? 0 : 1;
}
