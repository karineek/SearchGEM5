// Modification timestamp: 2023-08-04 14:11:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00103.c

int main() {
    int x;
    void *foo;
    void **bar;

    x = 0;

    foo = (void*)&x;
    bar = &foo;

    return **(int**)bar;
}
