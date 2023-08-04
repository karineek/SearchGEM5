// Modification timestamp: 2023-08-03 13:30:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00014.c

int main() {
    int x;
    int *p;

    x = 1;
    p = &x;
    p[0] = 0;
    return x;
}
