
// Modification timestamp: 2023-08-04 14:19:23
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00127.c

int c;

int main() {
    if (0) {
        return 1;
    } else if (0) {
    } else {
        if (1) {
            if (c)
                return 1;
            else
                return 0;
        } else {
            return 1;
        }
    }
    return 1;
}
