
// Modification timestamp: 2023-08-04 14:09:40
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00093.c

int a[] = {1, 2, 3, 4};

int main() {
    if (sizeof(a) != 4 * sizeof(int))
        return 1;

    return 0;
}
