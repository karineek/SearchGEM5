// Modification timestamp: 2023-08-14 14:44:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr20187-1.c
int a = 0x101;
int b = 0x100;

int
test (void)
{
  return (((unsigned char) (unsigned long long) ((a ? a : 1) & (a * b)))
	  ? 0 : 1);
}

int
main (void)
{
  return 1 - test ();
}
