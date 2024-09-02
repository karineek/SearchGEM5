// Modification timestamp: 2023-08-04 14:25:36
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00151.c

int arr[][3][5] = {
	{
		{ 0, 0, 3, 5 },
		{ 1, [3] = 6, 7 },
	},
	{
		{ 1, 2 },
		{ [4] = 7, },
	},
};

int main(void) {
	return !(arr[0][1][4] == arr[1][1][4]);
}
