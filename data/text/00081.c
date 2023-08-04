
// Modification timestamp: 2023-08-04 14:01:23
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00081.c

int main() {
    long long x;

    x = 0;
    x = x + 1;
    if (x != 1)
        return 1;
    return 0;
}
