// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00013.c

int main() {
    int x;
    int *p;

    x = 0;
    p = &x;
    return p[0];
}
