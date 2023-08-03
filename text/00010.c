// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00010.c

int main() {
    start:
        goto next;
        return 1;
    success:
        return 0;
    next:
    foo:
        goto success;
        return 1;
}
