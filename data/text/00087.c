// Modification timestamp: 2023-08-04 14:08:27
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00087.c

struct S
{
	int (*fptr)();
};

int foo()
{
    return 0;
}

int main()
{
    struct S v;

    v.fptr = foo;
    return v.fptr();
}
