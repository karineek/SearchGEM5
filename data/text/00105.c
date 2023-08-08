// Modification timestamp: 2023-08-04 14:11:26
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00105.c

int main() {
	int i;

	for(i = 0; i < 10; i++)
		if (!i)
			continue;

	return 0;
}
