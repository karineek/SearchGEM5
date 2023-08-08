// Modification timestamp: 2023-08-04 13:59:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00076.c

int main() {
    if (0 ? 1 : 0)
        return 1;
    if (1 ? 0 : 1)
        return 2;
    return 0;
}
