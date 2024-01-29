// Modification timestamp: 2023-08-03 17:16:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00027.c

int main() {
    int x;

    x = 1;
    x = x | 4;
    return x - 5;
}
