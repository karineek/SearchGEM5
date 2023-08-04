
// Modification timestamp: 2023-08-04 14:10:07
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00096.c

int x, x = 3, x;

int main() {
    if (x != 3)
        return 0;

    x = 0;
    return x;
}
