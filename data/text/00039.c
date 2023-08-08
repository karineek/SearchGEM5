// Modification timestamp: 2023-08-04 13:40:03
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00039.c

int main() {
    void *p;
    int x;

    x = 2;
    p = &x;

    if (*((int*)p) != 2)
        return 1;
    return 0;
}
