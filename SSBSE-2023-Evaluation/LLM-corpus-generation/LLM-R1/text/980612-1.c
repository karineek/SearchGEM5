// Modification timestamp: 2023-08-14 13:50:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980612-1.c
struct fd
{
	unsigned char a;
	unsigned char b;
} f = { 5 };

struct fd *g() { return &f; }
int h() { return -1; }

int main()
{
	struct fd *f = g();
	f->b = h();
	if (((f->a & 0x7f) & ~0x10) <= 2)
		abort ();
	exit (0);
}
