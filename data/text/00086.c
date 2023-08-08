// Modification timestamp: 2023-08-04 14:08:16
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00086.c

int main() {
    short x;

    x = 0;
    x = x + 1;
    if (x != 1)
        return 1;
    return 0;
}
