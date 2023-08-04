
// Modification timestamp: 2023-08-04 14:10:53
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00102.c

int main() {
	int x;

	x = 1;
	if ((x << 1) != 2)
		return 1;

	return 0;
}
