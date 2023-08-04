
// Modification timestamp: 2023-08-04 14:09:59
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00095.c

int x;
int x = 3;
int x;

int main();

void *
foo()
{
	return &main;
}

int
main()
{
	if (x != 3)
		return 0;

	x = 0;
	return x;
}
