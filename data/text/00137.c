
// Modification timestamp: 2023-08-04 14:22:19
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00137.c

#define x(y) #y

int main(void) {
    char *p;
    p = x(hello)  " is better than bye";
    return (*p == 'h') ? 0 : 1;
}
