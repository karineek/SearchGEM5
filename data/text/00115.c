c
// Modification timestamp: 2023-08-04 14:12:59
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00115.c

#define B "b"

char s[] = "a" B "c";

int main() {
    if (s[0] != 'a')
        return 1;
    if (s[1] != 'b')
        return 2;
    if (s[2] != 'c')
        return 3;
    if (s[3] != '\0')
        return 4;
    return 0;
}
