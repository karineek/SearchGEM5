
// Modification timestamp: 2023-08-04 13:39:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00038.c

int main() {
    int x, *p;

    if (sizeof(0) < 2)
        return 1;
    if (sizeof 0 < 2)
        return 1;
    if (sizeof(char) < 1)
        return 1;
    if (sizeof(int) - 2 < 0)
        return 1;
    if (sizeof(&x) != sizeof p)
        return 1;
    return 0;
}
