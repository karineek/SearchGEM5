
// Modification timestamp: 2023-08-04 14:08:59
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00090.c

int a[3] = {0, 1, 2};

int main() {
	if (a[0] != 0)
		return 1;
	if (a[1] != 1)
		return 2;
	if (a[2] != 2)
		return 3;

	return 0;
}
