
// Modification timestamp: 2023-08-04 14:08:35
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00088.c

int (*fptr)() = 0;


int main() {
    if (fptr)
        return 1;
    return 0;
}

