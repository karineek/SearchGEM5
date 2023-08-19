// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00007.c

int main() {
    int x;

    x = 1;
    for (x = 10; x; x = x - 1)
        ;
    if (x)
        return 1;
    x = 10;
    for (; x;)
        x = x - 1;
    return x;
}
