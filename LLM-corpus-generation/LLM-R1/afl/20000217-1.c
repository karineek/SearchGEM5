
// Modification timestamp: 2023-08-10 16:15:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Benchmarks/tramp3d-v4/tramp3d-v4.c

unsigned short int showbug(unsigned short int *a, unsigned short int *b)
{
        *a += *b -8;
        return (*a >= 8);
}

int main(int argc, char *argv[])
{
        unsigned short int x = 0;
        unsigned short int y = 10;

		if (argc != 3) {
			printf("Usage: %s <value1> <value2>\n", argv[0]);
			return 1;
		}

		x = atoi(argv[1]);
		y = atoi(argv[2]);

		if (showbug(&x, &y) != 0)
			abort ();

		exit (0);
}
