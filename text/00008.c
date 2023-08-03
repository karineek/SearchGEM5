// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00008.c

int main() {
    int x;

    x = 50;
    do {
        x = x - 1;
    } while (x);

    return x;
}
