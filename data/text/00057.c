
// Modification timestamp: 2023-08-04 13:51:12
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00057.c

int main() {
    char a[16], b[16];

    if(sizeof(a) != sizeof(b))
        return 1;
    return 0;
}
