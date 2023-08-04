
// Modification timestamp: 2023-08-04 13:37:46
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00035.c

int main() {
    int x;

    x = 4;
    if (!x != 0)
        return 1;
    if (!!x != 1)
        return 1;
    if (-x != 0 - 4)
        return 1;
    return 0;
}
