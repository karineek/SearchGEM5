// Modification timestamp: 2023-08-04 14:13:37
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00120.c

struct {
	enum { X } x;
} s;


int main() {
	return X;
}
