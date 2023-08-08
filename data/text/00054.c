// Modification timestamp: 2023-08-04 13:49:02
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00054.c

enum E {
	x,
	y,
	z,
};

int main() {
	enum E e;

	if(x != 0)
		return 1;
	if(y != 1)
		return 2;
	if(z != 2)
		return 3;

	e = x;
	return e;
}
