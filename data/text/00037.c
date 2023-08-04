
// Modification timestamp: 2023-08-04 13:38:57
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00037.c

int main() {
    int x[2];
    int *p;

    x[1] = 7;
    p = &x[0];
    p = p + 1;

    if(*p != 7)
        return 1;
    if(&x[1] - &x[0] != 1)
        return 1;

    return 0;
}
