// Modification timestamp: 2023-08-03 17:00:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00025.c

int strlen(char *);

int main() {
    char *p;

    p = "hello";
    return strlen(p) - 5;
}
