// Modification timestamp: 2023-08-14 17:11:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-13-BadLoad.c
unsigned long window_size = 0x10000;

unsigned test() {
	return (unsigned)window_size;
}

extern int printf(const char *str, ...);

int main() {
	printf("%d\n", test());
	return 0;
}
