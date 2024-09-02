// Modification timestamp: 2023-08-14 14:30:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-2c.c

extern void abort(void);
extern void exit(int);

int a[2];

__inline__ void f(int b, int o)
{
	unsigned int i;
	int *p;
	for (p = &a[b], i = b; --i < ~0;)
		*--p = i * 3 + o;
}

void g(int b)
{
	f(b, (int) &a);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int a[2];

	a[0] = a[1] = 0;
	g(atoi(argv[1]));
	if (a[0] != (int) &a || a[1] != (int) &a + 3)
		abort();
	exit(0);
}
