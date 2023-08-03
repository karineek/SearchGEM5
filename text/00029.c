// Modification timestamp: 2023-08-03 17:17:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00029.c

int main() {
    int x;

    x = 1;
    x = x ^ 3;
    return x - 2;
}
