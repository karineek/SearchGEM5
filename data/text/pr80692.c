// Modification timestamp: 2023-08-14 15:56:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr80692.c
/* { dg-require-effective-target dfp } */

int main () {
	_Decimal64 d64 = -0.DD;

	if (d64 != 0.DD)
		__builtin_abort ();

	if (d64 != -0.DD)
		__builtin_abort ();

	return 0;
}
