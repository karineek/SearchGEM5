// Modification timestamp: 2023-08-04 14:23:02
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00141.c

#define CAT(x,y) x ## y
#define XCAT(x,y) CAT(x,y)
#define FOO foo
#define BAR bar

int main(void) {
    int foo, bar, foobar;

    CAT(foo,bar) = foo + bar;
    XCAT(FOO,BAR) = foo + bar;
    return 0;
}
