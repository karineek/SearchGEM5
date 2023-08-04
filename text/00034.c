// Modification timestamp: 2023-08-03 18:01:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00034.c

int main() {
    int x;

    x = 0;
    while (1)
        break;
    while (1) {
        if (x == 5) {
            break;
        }
        x = x + 1;
        continue;
    }
    for (;;) {
        if (x == 10) {
            break;
        }
        x = x + 1;
        continue;
    }
    do {
        if (x == 15) {
            break;
        }
        x = x + 1;
        continue;
    } while (1);
    return x - 15;
}
