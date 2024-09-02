// Modification timestamp: 2023-08-04 14:25:36
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00151.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
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

	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int x = atoi(argv[1]);
	return !(arr[0][1][4] == arr[1][1][4]);
}
