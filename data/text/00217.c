// Modification timestamp: 2023-08-04 15:02:31
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00217.c

int printf(const char *, ...);
char t[] = "012345678";

int main(void)
{
    char *data = t;
    unsigned long long r = 4;
    unsigned a = 5;
    unsigned long long b = 12;

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    return 0;
}
