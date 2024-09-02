// Modification timestamp: 2023-08-14 14:42:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/packed-2.c
typedef struct s {
	unsigned short a;
	unsigned long b __attribute__ ((packed));
} s;

s t;

int main()
{
        t.b = 0;
	return 0;
}
