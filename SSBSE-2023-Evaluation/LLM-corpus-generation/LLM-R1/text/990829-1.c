// Modification timestamp: 2023-08-14 13:56:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990829-1.c
double test (const double le, const double ri)
{
	double val = ( ri - le ) / ( ri * ( le + 1.0 ) );
	return val;
}

int main ()
{
        double retval;

	retval = test(1.0,2.0);
        if (retval < 0.24 || retval > 0.26)
	  abort ();
	exit (0);
}
