// Modification timestamp: 2023-08-04 14:08:46
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00089.c

int zero()
{
	return 0;
}

struct S
{
	int (*zerofunc)();
} s = { &zero };

struct S * anon()
{
	return &s;
}

typedef struct S * (*fty)();

fty go()
{
	return &anon;
}

int main()
{
	return go()()->zerofunc();
}
