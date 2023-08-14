
// Modification timestamp: 2023-08-10 16:15:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Benchmarks/tramp3d-v4/tramp3d-v4.c

unsigned short int showbug(unsigned short int *a, unsigned short int *b)
{
        *a += *b -8;
        return (*a >= 8);
}

int main()
{
        unsigned short int x = 0;
        unsigned short int y = 10;

        if (showbug(&x, &y) != 0)
	  abort ();

	exit (0);
}
